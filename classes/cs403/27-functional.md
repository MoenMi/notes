# 27 - Functional

## List Functions

- `QUOTE` takes one parameter and returns the parameter without evaluation.
    - `QUOTE` is required because the Scheme interpreter, named `EVAL`, always evaluates parameters to function applications before applying the function. `QUOTE` is used to avoid parameter evaluation when it is not appropriate.
    - `QUOTE` can be abbreviated with the apostraphe prefix operator: `'(A B)` is equivalent to `(QUOTE (A B))`
- `CAR`, `CDR`, and `CONS`.

List representation and functions:

```{image} images/scheme-list-representation.png
:width: 500px
:align: center
```

Examples:
- `(CAR '((A B) C D))` returns `(A B)`
- `(CAR 'A)` is an error
- `(CDR '((A B) C D))` returns `(C D)`
- `(CDR 'A)` is an error
- `(CDR '(A))` returns `()`
- `(CONS '() '(A B))` returns `(() A B)`
- `(CONS '(A B) '(C D))` returns `((A B) C D)`
- `(CONS 'A 'B)` returns `(A . B)` (a dotted pair)

`LIST` is a function for building a list from any number of parameters.
- `(LIST 'apple 'orange 'grape)` returns `(apple orange grape)`

## Predicate Functions

`EQ?` takes two expressions as parameters (usually two atoms); it returns `#T` if both parameters have the same pointer value; otherwise `#F`.
- `(EQ? 'A 'A)` yields `#T`
- `(EQ? 'A 'B)` yields `#F`
- `(EQ? 'A '(A B))` yields `#F`
- `(EQ? '(A B) '(A B))` yields `#F` or `#T`
- `(EQ? 3.4 (+ 3 0.4))` yields `#F` or `#T`

`EQV?` is like `EQ?`, except that it works for both symbolic and numeric atoms; it is a value comparison, not a pointer comparison.
- `(EQV? 3 3)` yields `#T`
- `(EQV? 'A 3)` yields `#F`
- `(EQV? 3.4 (+ 3 0.4))` yields `#T`
- `(EQV? 3.0 3)` yields `#F` (floats and integers are different)

`LIST?` takes one parameter; it returns `#T` if the parameter is a list; otherwise `#F`.
- `(LIST? '())` yields `#T`

`NULL?` takes one parameter; it returns `#T` if the parameter is the empty list; otherwise `#F`
- `(NULL '(()))` yields `#F`

`member` takes an atom and a simple list; returns `#T` if the atom is in the list; `#F` otherwise

```scheme
(DEFINE (member atm a_list)
    (COND 
        ((NULL? a_list) #F)
        ((EQ? atm (CAR a_list)) #T)
        (ELSE (member atm (CDR a_list)))
))
```

`equalsimp` takes two simple lists as parameters; returns `#T` if the two simple lists are equal; `#F` otherwise.

```scheme
(DEFINE (equalsimp list1 list2)
(COND
    ((NULL? list1) (NULL? list2))
    ((NULL? list2) #F)
    ((EQ? (CAR list1) (CAR list2))
        (equalsimp(CDR list1) (CDR list2)))
    (ELSE #F)
))
```

`equal` takes two general lists as parameters; returns `#T` if the two lists are equal; `#F` otherwise.

```scheme
(DEFINE (equal list1 list2)
    (COND
        ((NOT (LIST? list1)) (EQ? list1 list2))
        ((NOT (LIST? list2)) #F)
        ((NULL? list1) (NULL? list2))
        ((NULL? list2) #F)
        ((equal (CAR list1) (CAR list2))
            (equal (CDR list1) (CDR list2)))
        (ELSE #F)
))
```

`append` takes two lists as parameters, returns the first parameter list with the elements of the second parameter list appended at the end.

```scheme
(DEFINE (append list1 list2)
    (COND
        ((NULL? list1) list2)
        (ELSE (CONS (CAR list1)
            (append (CDR list1) list2)))
))
```

`LET` is actually shorthand for a `LAMBDA` expression applied to a parameter.
- `(let ((<variable 1> <init 1> ...) <body>)` is the same as: `((lambda (<variable 1> .. ) <body>) <init 1> ...)`
- `(LET ((alpha 7)) (* 5 alpha))` is the same as `((LAMBDA (alpha) (* 5 alpha)) 7)`

```scheme
(DEFINE (quadratic_roots a b c)
    (LET (
        (root_part_over_2a
            (/ (SQRT (- (* b b) (* 4 a c))) (* 2 a)))
        (minus_b_over_2a (/ (- 0 b) (* 2 a))))
        (LIST (+ minus_b_over_2a root_part_over_2a)
            (- minus_b_over_2a root_part_over_2a))
))
```

## Tail Recursion

A function is **tail recursive** if its recursive call is the last operation in the function.

A tail recursive function can be automatically converted by a compiler to use iteration, making it faster.

Scheme language definition requires that Scheme language systems convert all tail recursive functions to use iteration.

Example of rewriting a function to make it tail recursive, using a helper function

Original:

```scheme
(DEFINE (factorial n)
    (IF (<= n 0)
        1
        (* n (factorial (- n 1)))
))
```

Tail recursive:

```scheme
(DEFINE (facthelper n factpartial)
    (IF (<= n 0)
        factpartial
        (facthelper (- n 1) (* n factpartial)))
)
(DEFINE (factorial n)
    (facthelper n 1))
```

## Functional Form

Composition
- If `h` is the composition of `f` and `g, h(x) = f(g(x))`

```scheme
(DEFINE (g x) (* 3 x))
(DEFINE (f x) (+ 2 x))
(DEFINE h x) (+ 2 (* 3 x)) "The composition"
```

- In Scheme, the functional composition function `compose` can be written:

```scheme
(DEFINE (compose f g) (LAMBDA (x) (f (g x))))
((compose CAR CDR) '((a b) c d))    "yields c"
(DEFINE (third_a_list)
    ((compose CAR (compose CDR CDR)) a_list)) "is equivalent to CADDR"
```

Apply-to-All - one form in Scheme is `map`
- Applies the given function to all elements of the given list

```scheme
(DEFINE (map fun a_list)
    (COND
        ((NULL? a_list) '())
        (ELSE (CONS (fun (CAR a_list))
            (map fun (CDR a_list))))
))
```

- `(map (LAMBDA (num) (* num num num)) '(3 4 2 6))` yields `(27 64 8 216)`

## Functions That Build Code

It is possible in Scheme to define a function that builds Scheme code and requests its interpretation.

This is possible because the interpreter is a user-available function, `EVAL`.

### Adding a List of Numbers

```scheme
(DEFINE (adder a_list)
    (COND
        ((NULL? a_list) 0)
        (ELSE (EVAL (CONS '+ a_list)
            user-initial-environment))
))
```

- The parameter is a list of numbers to be added' `adder` inserts a `+` operator and evaluates the resulting list.
    - Use `CONS` to insert the atom `+` into the list of numbers
    - Be sure that `+` is quoted to prevent evaluation
    - Submit the new list to `EVAL` for evaluation
