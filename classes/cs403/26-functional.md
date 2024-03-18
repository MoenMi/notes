# 26 - Functional

## Imperative vs. Functional Languages

The design of imperative languages is based directly on the **von Neumann Architecture**, where efficiency is the primary concern, rather than the suitability of the language for software development.

The design of functional languages is based on **mathematical functions**. This provides a solid theoretical basis that is closer to the user, but relatively unconcerned with the architecture of the machines on which programs will run.

## Mathematical Functions

A mathematical function is a **mapping** of members of one set, called the **domain set**, to another set, called the **range set**.

A **lambda expression** specifies the parameter(s) and mapping of a function in the following form:

$$ \lambda(x) \ x \ * \ x \ * \ x $$

for the function `cube(x) = x * x * x`.

### Lambda Functions

Lambda expressions describe nameless functions. They are applied to parameters by placing the parameter(s) after the expression, e.g.

$$ (\lambda \ x \ * \ x \ * \ x)(2) $$

which evaluates to $8$.

### Functional Forms

A higher-order function, or **functional form**, is one that either takes functions as parameters or yields a function as its result, or both.

### Function Composition

A functional form that takes two functions as parameters and yields a function whose value is the first actual parameter function applied to the result of the second.

Form: $h \equiv f \circ g$, which means $h(x) \equiv f(g(x))$.

For $f(x) \equiv x + 2$ and $g(x) \equiv 3x$, $h \equiv f \circ g$ yields $h(x) \equiv 3x + 2$.

### Apply-to-all

A functional form that takes a single function as a parameter and yields a list of values obtained by applying the given function to each element of a list of parameters.

Form: $\alpha$

For $h(x) \equiv x * x$, $\alpha(h, (2,3,4))$ yields $(4, 9, 16)$.

## Fundamentals of Functional Programming Languages

The objective of the design of an FPL is to mimic mathematical functions to the greatest extent possible.

The basic process of computation is fundamentally different in an FPL than in an imperative language.
- In an imperative language, operations are done and the results are stored in variables for later use
- Management of variables is a constant concern and source of complexity for imperative programming

In an FPL, variables are not necessary, as is the case in mathematics.

**Referential transparency**: In an FPL, the evaluation of a function always produces the same result given the same parameters.

## Lisp

### Data Types and Structures

- **Data object types**: originally only atoms and lists
- **List form**: paranthesized collections of sublists and/or atoms, e.g. `A B (C D) E`
- Originally, Lisp was a typeless language
- Lisp lists are stored internally as singly-linked lists

```{image} images/lisp-list.png
:width: 450px
:align: center
```

### Interpretation

Lambda notation is used to specify functions and function definitions. Function applications and data have the same form.

For example, if the list `(A B C)` is interpreted as data, it is a simple list of three atoms, `A`, `B`, and `C`. If it is interpreted as a function application, it means the that the function named `A` is applied to the two parameters `B` and `C`.

The first Lisp interpreter appeared only as a demonstation of the universality of the computational capabilities of the notation.

## Scheme

Scheme was originally a mid-1970s dialect of Lisp, designed to be a cleaner, more modern, and simpler version of the contemporary dialects of Lisp.

Scheme uses only static scoping.

Functions in Scheme are first-class entities:
- They can be the values of expressions and elements of lists
- They can be passed as parameters and returned from functions

### The Scheme Interpreter

In interactive mode, the Scheme interpreter is an infinite read-evaluate-print loop (REPL). This form of interpreter is also used by Python and Ruby.

Expression are evaluated by the function `EVAL`.

Literals evaluate to themselves.

### Primitive Function Evaluation

- Parameters are evaluated in no particular order
- The values of the parameters are substituted into the function body
- The function body is evaluated
- The value of the last expression in the body is the value of the function

### Primitive Functions & `LAMBDA` Expressions

- Primitive Arithmetic Functions: `+`, `-`, `*`, `/`, `ABS`, `SQRT`, `REMAINDER`, `MIN`, `MAX`
    - e.g. `(+ 5 2)` yields `7`
- Lambda Expressions
    - Form is based on $\lambda$ notation
    - e.g. `(LAMBDA (x) (* x x))`
    - `x` is called a bound variable
- Lambda expressions can be applied to parameters
    - e.g. `((LAMBDA (x) (* x x)) 7)`
- Lambda expressions can have any number of parameters
    - `(LAMBDA (a b c x) (+ (* a x x) (* b x) c))`

### Special Form Function: `DEFINE`

`DEFINE` has 2 forms:
1. To bing a symbol to an expression
    - e.g. `(DEFINE pi 3.141593)`
    - `(DEFINE two_pi (* 2 pi))` - These symbols are not variables, they are like the names bound by Java's `final` declaration
2. To bind names to lambda expressions (`LAMBDA` is explicit)
    - e.g. `(DEFINE (square x) (* x x))`
    - `(square 5)`

The evaluation process for `DEFINE` is different. The first parameter is never evaluated. The second parameter is evaluated and bound to the first parameter.

### Numeric Predicate Functions

- `#T` (or `#t`) is true and `#F` (or `#f`) is false
    - Sometimes `()` is used for false
- `=`, `>`, `<`, `>=`, `<=`
- `EVEN?`, `ODD?`, `ZERO?`, `NEGATIVE?`
- The `NOT` function inverts the logic of a Boolean expression

### Control Flow

- Selection - the special form `IF`
    - `(IF predicate then_expr else_expr)`

```Scheme
(define (factorial n)
    (if (<= n 1)
        1
        (* n (factorial (- n 1)))
    )
)
```

```Scheme
(DEFINE (leap? year)
    (COND
        ((ZERO? (MODULO year 400)) #T)
        ((ZERO? (MODULO year 100)) #F)
        (ELSE (ZERO? (MODULO year 4))) ))
```

### MIT/GNU Scheme

```bash
ssh username@cs-parallel.ua.edu
```

```Scheme
scheme
    1 ]=> (* 3 4 5)
    ;Value: 60
    1 ]=> (SQRT 4)
    ;Value: 2
    1 ]=> (exit)
```

You can also type `CTRL-D` to exit.
