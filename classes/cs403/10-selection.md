# 10 - Selection

## Statement-Level Control Structures

Levels of control flow:
- Within expressions
- Among program units
- Among program statements

A single-level control statement (a selectable goto) is minimally sufficient. It was proven that all algorithms represented by flowcharts can be coded with only two-way selection and pretest logical loops, and the unconditional branch statement is nonessential. Including more control statements enhances readability and writability.

A **selection statement** provides the means of choosing between two or more paths of execution. These generally fall into two-way or multiple-way selectors.

## Two-way Selection Statements

Two-way selection statements generally take the following form:

```
if control_expression
    then clause
    else clause
```

These statements raise the following design issues:
- What is the form and type of the control expression?
- How are the `then` and `else` clauses specified?
- How should the meaning of nested selectors be specified?

### The Control Expression

If the `then` reserved word or some other syntactic marker is not used to introduce the then clause, the expression is placed in parantheses.

In C89, C99, Python, and C++, the control expression can be arithmetic. In most other languages, the control expression must be Boolean.

### Clause Form

In many contemporary languages, the then and else clauses can be single statements or compound statements.

In Perl, all clauses must be delimited by braces. In Python and Ruby, clauses are statement sequences. Python uses indentation to define clauses:

```Python
if x > y:
    x = y
    print('x was greater than y')
```

### Nesting Selectors

```Java
if (sum == 0)
    if (count == 0)
        result = 0;
else result = 1;
```

In this example, the `else` clause applies to the second `if` block.

To force alternative semantics, compound statements may be used:

```Java
if (sum == 0) {
    if (count == 0)
        result = 0;
} else result = 1;
```

The above solution applies to C, C++, and C# as well.

### Selector Expressions

In ML, F#, and Lisp, the selector is an expression. In F#:

```F#
let y =
    if x > 0 then x
    else 2 * x
```

The types of the values returned must by then and else clauses must be the same. If there is no else clause, the then clause must return a unit type which means no value.

## Multiple-way Selection Statements

**Multiple-way selection statements** allow the selection of any number of statements or statement groups.

Design issues:
- What is the form and type of the control expression?
- How are the selectable segments identified?
- Is execution flow through the structure restricted to include just a single selectable segment?
- How are case values specified?
- What is done about unrepresented expression values?

#### In C, C++, Java, and JavaScript

```C
switch (expression) {
    case const_expr1: stmt1;
    ...
    case const_exprn: stmtn;
    [default: stmt;]
}
```

This implementation for C's `switch` statement makes the following design choices:
- Control expression can only be of integer type.
- Selectable segments can be statement sequences or compound statements.
- Any number of segments can be executed in one execution of the construct (there is no implicit branch at the end of selectable segments).
- The `default` clause is for unrepresented values (if there is no `default` clause, then no statement executes in this case).

#### In C#

C# differs from C in that it has a static semantics rule that disallows the implicit execution of more than one segment. Each selectable segment in C# must end with an unconditional branch (`goto case`, `break`, `return`). Also, in C# the control expression and the case constants can be strings.

### Implementing Multiple Selectors

There are several approaches:
- Multiple conditional branches
- Store case values in a table and use a linear search of the table
- When there are more than 10 cases, a hash table of case values can be used
- If the case values are small and more than half of the whole range of case values are represented, an array whose indices are the case values are the case labels can be used

#### Multiple-way Selection Using `if`

Multiple selectors can appear as direct extensions to two-way selectors, using else-if clauses.

Example in Python:

```Python
if count < 10:
    bag1 = True
elif count < 100:
    bag2 = True
elif count < 1000:
    bag3 = True
```

Example in Ruby:

```Ruby
case
    when count < 10 then bag1 = true
    when count < 100 then bag3 = true
    when count < 1000 then bag3 = true
end
```

#### Scheme's Multiple Selector

General form of a call to `COND`:

```Scheme
(COND
    (predicate1 expression1)
    ...
    (predicaten expressionn)
    [(ELSE expression)]
)
```

- The `ELSE` clause is optional; `ELSE` is a synonym for true
- Each predicate-expression pair is a parameter
- Semantics: The value of the evaluation of `COND` is the value of the expression associated with the first predicate expression that is true
