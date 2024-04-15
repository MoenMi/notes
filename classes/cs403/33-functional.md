# 33 - Functional

## ML (Meta Language)

- A static-scoped language with syntax that is closer to Pascal than to Lisp
- It is strongly typed (whereas Scheme is essentially typeless) and has no type coercions
- Uses type declarations, but also does **type inferencing** to determine the types of undeclared variables
- Does not have imperative-style variables; its identifiers are untyped names for values
- Includes lists and list operations
- A table called the **evaluation environment** stores the names of all identifiers in a program, along with their types (like a run-time symbol table)
- Function declaration form:

```ml
fun name(formal parameters) = expression;
fun cube(x : int) = x * x * x;
```

- The type could be attached to a return value, as in

```ml
fun cube(x) : int = x * x * x;
```

- With no type specified, it would default to `int` (the default for numeric values)
- User-defined overloaded functions are not allowed, so if we wanted a `cube` function for real parameters, it would need to have a different name

### Selection

```ml
if expression then then_expression
    else else_expression
```

where the first expression must evaluate to a Boolean value.

Pattern matching is used to allow a function to operate on different parameter forms:

```ml
fun fact(0) = 1
|   fact(1) = 1
|   fact(n : int) : int = n * fact(n - 1)
```

### Lists

Literal lists are specified in brackets: `[3, 5, 7]`.
- `[]` is the empty list
- `CONS` is the binary prefix operator, `::`
    - `4 :: [3, 5, 7]`, which evaluates to `[4, 3, 5, 7]`
- `CAR` is unary operator `hd`
- `CDR` is the unary operator `tl`

```ml
fun length([]) = 0
|   length(h :: t) = 1 + length(t);

fun append([], lis2) = lis2
|   append(H :: t, lis2) = h :: append(t, lis2);
```

### The `val` Statement

The `val` statement binds a name to a value (similar to `DEFINE` in Scheme).

```ml
val distance = time * speed;
```

- As is the case with `DEFINE`, `val` is nothing like an assignment statement in an imperative language
- If there are two `val` statements for the same identifier, the first is hidden by the second
- `val` statements are often used in `let` constructs

```ml
let
    val radius = 2.7
    val pi = 3.14159
in
    pi * radius * radius
end;
```

### `filter`

- A higher-order filtering function for lists
- Takes a predicate function as its parameter, often in the form of a lambda expression
- Lambda expressions are defined like functions, except with the reserved word `fn`

```ml
filter(fn(x) => x < 100, [25, 1, 711, 50, 100]);
```

This returns `[25, 1, 50]`.

### `map`

- A higher-order function that takes a single parameter, a function
- Applies the parameter function to each element of a list and returns a list of results

```ml
fun cube x = x * x * x;
val cubeList = map cube;
val newList = cubeList [1, 3, 5];
```

This sets `newList` to `[1, 27, 125]`.

Alternatively, you can use a lambda expression

```ml
val newList = map(fn x => x * x * x, [1, 3, 5]);
```

### Function Composition

Use the binary operator, o

```ml
val h = g o f;
```

## Haskell

- Similar to ML (syntax, static scoped, strongly typed, type inferencing, pattern matching)
- Different from ML (and most other functional languages) in that it is *purely* functional (e.g. no variables, no assignment statements, and no side effects of any kind)

Syntax differences from ML:

```haskell
fact 0 = 1
fact 1 = 1
fact n = n * fact(n - 1)
```

```haskell
fib 0 = 1
fib 1 = 1
fib(n + 2) = fib(n + 1) + fib n
```

### Function Definitions with Different Parameter Ranges

```haskell
fact n
|   n == 0 = 1
|   n == 1 = 1
|   n > 0 = n * fact(n - 1)
```

```haskell
sub n
|   n < 10      = 0
|   n > 100     = 2
|   otherwise   = 1
```

```haskell
square x = x * x
```

- Because Haskell supports polymorphism, this works for any numeric type of `x`

### Lists

- List notation: Put elements in brackets `[]`
    - e.g. `directions = ["north", "south", "east", "west]`
- Length: `#`
    - e.g. `#directions` is `4`
- Arithmetic series with the `..` operator
    - e.g. `[2, 4..10]` is `[2, 4, 6, 8, 10]`
- Catenation is with `++`
    - e.g. `[1, 3] ++ [5, 7]` results in `[1, 3, 5, 7]`
- `head, tail, :, for CAR, CDR, CONS`
    - e.g. `1:[3, 5, 7]` results in `[1, 3, 5, 7]`

### Pattern Parameters

```haskell
product[] = 1
product(a:x) = a * product x
```

Factorial:

```haskell
fact n = product [1..n]
```

### List Comprehensions

```haskell
[n * n * n | n <- [1..50]]
```
- The qualifier in this example has the form of a **generator**. It could be in the form of a test

```haskell
factors n = [i | i <- [1..n `div` 2], n `mod` i == 0]
```

The backticks specify the function is used as a binary operator.

### Quicksort

```haskell
sort [] = []
sort (h:t) =
    sort [b | b <- t, b <= h]
    ++ [h] ++
    sort [b | b <- t, b > h]
```

### Lazy Evaluation

- A language is **strict** if it requires all actual parameters to be fully evaluated.
- A language is **nonstrict** if it does not have the strict requirement
- Nonstrict languages are more efficient and allow some interesting capabilities - **infinite lists**
- **Lazy evaluation** - Only compute those values that are necessary
- Positive numbers: `positives = [0..]`

Ex. Determining if `16` is a square number

```haskell
member [] b = False
member(a:x) b=(a == b) || member x b
squares = [n * n | n <- [0..]]
member squares 16
```

### Member Revisited

The member function could be written as:

```haskell
member b [] = False
member b (a:x) = (a == b) || member b x
```

However, this would only work if the parameter to squares was a perfect square; if not, it will keep generating them forever. The following version will always work:

```haskell
member2 n (m:x)
    | m < n = member2 n x
    | m == n = True
    | otherwise = False
```

## F#

- Based on Ocaml, which is a descendent of ML and Haskell
- Fundamentally a functional language, but with imperative features and OOP support
- Has a full-featured IDE, an extensive library of utilities, and interoperates with other .NET languages
- Includes tuples, lists, discriminated unions, records, and both mutable and immutable arrays
- Supports generic sequences, whose values can be created with generators and through iteration

### Sequences

```f#
let x = seq {1..4};;
```

- Generation of sequence values is lazy
    ```f#
    let y = seq {0..10000000};;
    ```
    - Sets `y` to `[0; 1; 2; 3; ...]`
- Default stepsize is `1`, but it can be any number
    ```f#
    let seq1 = seq {1..2..7};;
    ```
    - Sets `seq1` to `[1; 3; 5; 7]`
- Iterators to create sequences

```f#
let cubes = seq {for i in 1..4 -> (i, i * i * i)};;
```
- Sets cubes to `[(1, 1); (2, 8); (3, 27); (4, 64)]`

### Functions

- If named, defined with `let`; if lambda expressions, defined with `fun`

```f#
let add a b = a + b;;
(fun a b -> a + b)
```

- No difference between a name defined with `let` and a function without parameters
- The extent of a function is defined by indentation

```f#
let f =
    let pi = 3.14159
    let twoPi = 2.0 * pi
    twoPi;;
```

If a function is recursive, its definition must include the `rec` reserved word

```f#
let rec factorial n =
    if n <= 1 then 1
    else n * factorial(n - 1)
```

Names in functions can be outscoped, which ends their scope.

```f#
let x4 x =
    let x = x * x
    let x = x * x
    x;;
```

The first `let` in the body of the function creates a new version of `x`; this terminates the scope of the parameter. The second `let` in the body creates another `x`, terminating the scope of the second `x`.

### Functional Operators

The pipeline (`|>`)
- A binary operator that sends the value of its left operand to the last parameter of the call (the right operand)

    ```f#
    let myNums = [1; 2; 3; 4; 5]
    let evensTimesFive = myNums
        |> List.filter(fun n -> n % 2 = 0)
        |> List.map(fun n -> 5 * n)
    ```
- The return value is `[10; 20]`

Composition (`>>`)
- Builds a function that applies its left operand to a given parameter (a function) and then passes the result returned from the function to its right operand (another function)
- The F# expression `(f >> g) x` is equivalent to the mathematical expression $g(f(x))$

### Why F# Is Interesting

- It builds on previous functional languages
- It supports virtually all programming methodologies in use today
- It is the first functional language that is designed for interoperability with other widely used languages
- At its release, it had an elaborate and well-developed IDE and libary of utility software
