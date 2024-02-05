# 9 - Assignment

## Arithmetic Expressions

Arithmetic evaluation was one of the motivations for the development of the first programming languages.

Arithmetic expressions consist of operators, operands, parantheses, and function calls.

In most languages, binary operators are infix, except in Scheme and LISP, in which they are prefix.

Most unary operators are prefix, but the `++` and `--` operators in C-based languages can be either prefix or postfix.

Arithmetic expressions must consider the following design issues:
- Operator precedence rules?
- Operator associativity rules?
- Order of operand evaluation?
- Operand evaluation side effects?
- Operator overloading?
- Type mixing in expressions?

### Operator Precedence Rules

The **operator precedence rules** for expression evaluation define the order in which "adjacent" operators of different precendence levels are evaluated.

Typical precendence levels:
- Parantheses
- Unary operators
- `**`
- `*`, `/`
- `+`, `-`

### Operator Associativity Rules

The **operator associativity rules** for an expression evaluation define the order in which adjacent operators with the same precedence level are evaluated.

Typical associativity rules are left to right, except `**`, which is right to left.

APL is different; all operators have equal precedence and all operators associate right to left.

Precedence and associativity rules can be overriden with parantheses.

### Side Effects



### Referential Transparency



### Overloaded Operators



### Type Conversions



## Relational Expressions



## Boolean Expressions



### Short Circuit Evaluation



## Assignment Statements


