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

### Expressions in Ruby and Scheme

In Ruby, a pure object-oriented language, all arithmetic, relational, and assignment operators, as well as array indexing, shifts, and bit-wise logic operators are implemented as methods. One result of this is that these operators can be overriden by application programs.

In Scheme and Common Lisp, all arithmetic and logic operations are performed by explicitly called subprograms (ex. `a + b * c` is coded as `(+ a (* b c))`).

### Conditional Expressions (Ternary Operator)

Conditional expressions are found in C-based languages.

```C
average = (count == 0) ? 0 : sum / count;
```

Evaluates as if written as follows:

```C
if (count == 0)
    average = 0
else
    average = sum / count
```

### Operand Evaluation Order

Operands are evaluated in the following order:
1. Variables: fetch the value from memory
2. Constants: sometimes a fetch from memory; sometimes the constant is in the machine language instruction
3. Paranthesized instructions: evaluate all operands and operators first
4. The most interesting case is when the operand is a function call

### Side Effects

A **functional side effect** is when a function changes a two-way parameter or a non-local variable.

The problem with functional side effects occurs when a function referenced in an expression alters another operand of the expression.

```C
a = 10;
b = a + foo(&a); // Assume foo() changes a
```

There are 2 possible solutions for the problem of functional side effects:
1. Write the language definition to disallow functional side effects
    - No two-way parameters in functions
    - No non-local references in functions
    - *Advantage:* it works
    - *Disadvantage:* inflexibility of one-way parameters and lack of non-local references
2. Write the language definition to demand that operand evaluation order be fixed.
    - *Disadvantage:* limits some compiler optimizations
    - Java requires that operands appear to be evaluated in left-to-right order

### Referential Transparency

A program has the property of **referential transparency** if any two expressions in the program that have the same value can be substituted for one another anywhere in the program without affecting the action of the program.

```C
result1 = (foo(a) + b) / (foo(a) - c);
temp = foo(a);
result2 = (temp + b) / (temp - c);
```

- If `foo` has no side effects, `result1 = result2`; otherwise, this is not the case and referential transparency is violated 

### Overloaded Operators

Use of an operator for more than one purpose is called **operator overloading**. Some of these are common (e.g. `+` for `int` and `float`).

Some overloaded operators can cause issues (e.g. `&` in C/C++).
- Loss of compiler error detection (omission of an operand should be a detectable error)
- Some loss of readability

C++, C#, and F# allow user-defined overloaded operators.
- When sensibly used, such operators can be an aid to readability (avoid method calls, expressions appear natural)
- Potential problems:
    - Users can define nonsense operations
    - Readability may suffer, even when operators make sense

### Type Conversions

A **narrowing conversion** is one that converts an object to type that cannot include all of the values of the original type (e.g. `float` into `int`).

A **widening conversion** is one in which an object is converted to a type that can include at least approximations to all of the values of the original type (e.g. `int` to `float`).

#### Mixed Mode

A **mixed mode** conversion is one that has operands of different types.

A **coercion** is an implicit type conversion.
- *Disadvantage:* decreases the type error detection ability of the compiler

In most languages, all numeric types are coerced in expressions, using widening conversions. However, in ML and F#, there are no coercions in expressions.

#### Explicit Type Conversions

Explicit type conversions are called **casting** in C-based languages:

In C,
```C
(int) angle
```

In F#,
```F#
float(sum)
```
- Note that F#'s syntax is similar to that of function calls

## Relational and Boolean Expressions

### Relational Expressions

Relational expressions
- Use relational operators and operands of various types
- Evaluate to some Boolean representation
- Operator symbols used vary somewhat among languages (`!=`, `/=`, `~=`, `.NE`, `<>`)

Javascript and PHP have two additional relational operators `===` and `!==`. These operators are similar to `==` and `!=`, except they do not coerce their operands

Ruby uses `==` for an equality relation operator that uses coercions and `eql?` for those that do not.

### Boolean Expressions

Boolean expressions have operands that are Boolean and a Boolean result (e.g. `&&`, `||`, `!`).

C89 has no Boolean type, so it uses an `int` type with with 0 for false and nonzero for true.

One odd characteristic of C's expressions: `a < b < c` is a legal expression, but the result is not what you'd expect:
- The left operator is evaluated, producing 0 or 1
- The evaluation result is then compared with the third operand (i.e. `c`)

### Short Circuit Evaluation

Short circuit evaluation is when an expression is determined without evaluating all of the operands and/or operators. For example, in `(13 * a) * (b / 13 - 1)`, if `a` is 0, then there is no need to evaluate the second set of parantheses.

Problem with non-short-circuit evaluation:

```
index = 0;
while (index < length) && (LIST[index] != value)
    index++;
```
- When `index = length`, `LIST[length]` will cause an indexing problem (assuming `LIST` is `length` long)

C, C++, and Java use short-circuit evaluation for the usual Boolean operators (`&&` and `||`), but also provide bitwise Boolean operators that are not short circuit (`&` and `|`).

All logic operators in Ruby, Perl, ML, F#, and Python are short-circuit evaluated.

Short-circuit evaluation exposes the potential problem of side effects in expressions (e.g. `(a > b) || (b++ / 3)`).

## Assignment Statements

General syntax:
```
<target_var> <assignment_operator> <expression>
```

The assignment operator is `=` in Fortran, BASIC, and C-based languages, and `:=` in Ada.

The `=` operator can be bad when overloaded for the relational operator for equality (that's why the C-based languages use `==` as the relational operator).

### Conditional Targets

In Perl,
```Perl
($flag ? $total : $subtotal) = 0
```

This is equivalent to:
```Perl
if ($flag) {
    $total = 0
} else {
    $subtotal = 0
}
```

### Compound Assignment Operators

Compound assignment operators are a shorthand method of specifying a commonly needed form of assignment.

This method was introduced in ALGOL and adopted by C-based languages:
```
a += b
```

### Unary Assignment Operators

Unary assignment operators in C-based languages combine increment and decrement operations with assignment.

For example:
```C
sum = ++count;  // count incremented then assigned to sum
sum = count++;  // count assigned to sum then incremented
count++;        // count incremented
-count++;       // count incremented then negated
```

### Assignment as an Operand

In C-based languages, Perl, and JavaScript, the assignment statement produces a result and can be used as an operand:

```C
while ((ch = getchar()) != EOF) {...}
```
- `ch = getchar()` is carried out; the result (assigned to `ch`) is used as a conditional value for the `while` statement

The disadvantage of this is that it is another side effect.

### Multiple Assignments

Perl and Ruby allow multiple-target multiple-source assignment:
```Perl
($first, $second, $third) = (20, 30, 40);
```

Also, the following is legal and causes a swap:
```Perl
($first, $second) = ($second, $first);
```

### Mixed-Mode Assignment

Assignment statements can also be mixed-mode.

In Fortran, C, Perl, and C++, any numeric type value can be assigned to any numeric type variable.

In Java and C#, only widening assignment coercions are done.

In Ada, there is no assignment coercion.
