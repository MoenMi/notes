# 4 - Semantics

## Static Semantics

Static semantics have nothing to do with meaning.

Context-free grammars (CFGs) cannot describe all of the syntax of programming languages. Some categories of constructs in particular are in trouble:
- Context-free, but cumbersome (e.g. type compatibility rules)
- Non-context-free (e.g. variables must be declared before they are used)

Is this legal in Java?
```Java
int A, B;
double C;
A = B + C;
```

No, Java does not automatically cast the result on the right to an `int`.

### Attribute Semantics

An **attribute grammar** is a context-free grammar $G =(S, N, T, P)$ with the following additions:
- For each grammar symbol $x$ there is a set $A(x)$ of attribute values
- Each rule has a set of functions that define certain attributes of the nonterminals in the rule
- Each rule has a (possibly empty) set of predicates to check for attribute consistency

Let $X_0 \rightarrow X_1 \dots X_n$ be a rule
- Functions of the form $S(X_0) = f(A(X_1), \dots, A(X_n))$ define *synthesized attributes*
- Functions of the form $I(X_j) = f(A(X_0), \dots, A(X_{j-1}))$ define *inherited attributes* 
- Initially, there are *instrinsic attributes* on the leaves

```
<assign> -> <var> = <expr>
<expr> -> <var> + <var> | <var>
<var> -> A | B | C
```

- The `actual_type` is synthesized for `<var>` and `<expr>`
- The `expected_type` is inherited for `<expr>`

Semantic rules:
1. Syntax Rule: `<assign> -> <var> = <expr>`
    - Semantic Rule: `<expr>.expected_type <- <var>.actual_type`
2. Syntax Rule: `<expr> -> <var>[2] + <var>[3]`
    - Semantic Rule: 
    ```
    <expr>.actual_type <-
        if (<var>[2].actual_type = int)
            and (<var>[3].actual_type = int)
        then int
        else real
        end if
    ```
    - Predicate: `<expr>.actual_type == <expr>.expected_type`
3. Syntax Rule: `<expr> -> <val>`
    - Semantic Rule: `<expr>.actual_type <- <var>.actual_type`
    - Predicate: `<expr>.actual_type == <expr>.expected_type`
4. Syntax Rule: `<var> -> A | B | C`
    - Semantic Rule: `<var>.actual_type <- look-up(<var>.string)`

How are attribute grammars computed?
- If all attributes were inherited, the tree could be decorated in top-down order.
- If all attributes were syntesized, the tree could be decorated in in bottom-up order.
- In many cases, both kinds of attributes are used, and it is some combination of top-down and bottom-up that must be used.

## Dynamic Semantics

There are several needs for a methodology and notation for semantics:
- Programmers need to know what statements mean
- Compiler writers must know exactly what language constructs do
- Correctness proofs would be possible
- Compiler generators would be possible
- Designers could detect ambiguities and inconsistencies

### Operational Semantics

**Operational semantics** describe the meaning of a program by executing its statements on a machine, either simulated or actual. The change in the state of the machine (memory, registers, etc.) defines the meaning of the statement. To use operational semantics for a high-level language, a virtual machine is needed.

#### Example

C statement:
```C
for (expr1; expr2; expr3) {
    . . .
}
```

Meaning:
```
        expr1;
loop:   if expr2 == 0 goto out
        . . .
        expr3;
        goto loop;
out:    . . . 
```

### Denotational Semantics

Originally developed by Scott and Strachey in 1970, denotational semantics are based on recursive function theory and are the ost abstract semantics description method.

The process of building a denotational specification for a language:
- Define a mathematical object for each language entity
- Define a function that maps instances of the language entities onto instances of the corresponding mathematical objects

Denotational semantics are called *denotational* because the mathematical objects denote the meaning of their corresponding syntactic entities.

#### Program State

The state of a program is the values of all its current variables:

$$ s = \{<i_1, v_1>, <i_2, v_2>, ..., <i_n, v_n>\} $$

Let **VARMAP** be a function that, when given a variable name and a state, returns the current value of the variable:

$$ \text{VARMAP}(i_j, s) = v_j $$

#### Decimal Numbers

```
<dec_num> -> '0' | '1' | '2' | '3' | '4' |
             '5' | '6' | '7' | '8' | '9' |
             <dec_num> ('0' | '1' | '2' | '3' |
                        '4' | '5' | '6' | '7' |
                        '8' | '9')

M_dec('0') = 0, M_dec('1') = 1, ..., M_dec('9') = 9
M_dec(<dec_num> '0') = 10 * M_dec(<dec_num>)
M_dec(<dec_num> '1') = 10 * M_dec(<dec_num>) + 1
...
M_dec(<dec_num> '9') = 10 * M_dec(<dec_num>) + 9
```

#### Expressions

Map expressions onto Z $\cup$ {error}

```
<expr> -> <dec_num> | <var> | <binary_expr>
<binary_expr> -> <left_expr> <operator> <right_expr>
<left_expr> -> <dec_num> | <var>
<right_expr> -> <dec_num> | <var>
<operator> -> + | *
```

```
M_e(<expr>, s) delta =
    case <expr> of
        <dec_num> => M_dec(<dec_num>, s)
        <var> =>
            if VARMAP(<var>, s) == undef
                then error
                else VARMAP(<var>, s)
        <binary_expr> =>
            if M_e(<binary_expr>.<left_expr>, s) == '+' then
                M_e(<binary_expr>.<left_expr>, s)
                    + M_e(<binary_expr>.<right_expr>, s)
            else M_e(<binary_expr>.<left_expr>, s)
                * M_e(<binary_expr>.<right_expr>, s)
```

#### Assignment Statements

Map state sets to state sets $\cup$ {error}

```
M_a(x = E, s) delta =
    if M_e(E, s) == error
        then error
    else s' = {<i1, v1'>, <i2, v2'>, ..., <in, vn'>}, where
        for j = 1, 2, ..., n
            if ij == x
                then vj' = M_e(E, s)
                else vj' = VARMAP(ij, s)
```

#### Logical Pretest Loops

Map state sets to state sets $\cup$ {error}

```
M_1(while B do L, s) delta =
    if M_b(B, s) == undef
        then error
    else if M_b(B, s) == false
        then s
        else if M_sl(L, s) == error
            then error
            else M_1(while B do L, M_sl(L, s))
```

### Axiomatic Semantics

Based on mathematical logic, the original purpose of axiomatic semantics was formal program verification.

An **assertion** before a statement (a *precondition*) states the relationships and constraints among variables that are true at that point in execution.
- An assertion following a statement is a *postcondition*.
- A *weakest precondition* is the least restrictive precondition that will guarantee the postcondition.

In **axiomatic semantics**, the meaning of a specific statement is defined by its precondition and postcondition. The two assertions specify precisely the effect of executing the statement. Axioms or inference rules are defined for each statement type in the language.

#### Form

Pre-, post-form: `{P} statement {Q}`

An example:
- `a = b + 1 {a > 1}`
- One possible precondition: `{b > 10}`
- Weakest precondition: `{b > 0}`

#### Assignment

An axiom for assignment statements ($x = E$): $Q_{x \rightarrow E} x = E \{Q\}$
- `a = b + 1 {a > 1}`
- $Q$: $a > 1$
- $P$ or $Q_{x \rightarrow E}$: $a > 1$ or $b + 1 > 1$ or $b > 0$

#### Sequences

An inference rule for sequences of the form S1; S2

```
{P1} S1 {P2}
{P2} S2 {P3}
```

$$ \frac{\{P1\}S1\{P2\}, \{P2\}S2\{P3\}}{\{P1\}S1; S2\{P3\}} $$

#### Selection

An inference rule for selection: `if B then S1 else S2`

$$ \frac{\{\text{B and P}\} \text{ S1 } \{\text{Q}\}, \{ \text{(not B) and P} \} \text{ S2 } \{Q\}}{\{\text{P}\} \text{ if B then S1 else S2 } \{Q\}} $$

- If $x>0$ then $y=y-1$ else $y=y+1 \ \{y>0\}$
- $y=y-1 \ \{y>0\} \ $, $\text{P:} \{y>1\}$
- $y=y+1 \ \{y>0\} \ $, $\text{P:} \{y>-1\}$
- $\text{P:} \{y>-1\}$ for the if statement

#### Loops

An inference test for logical pretest loops: `{P} while B do S end {Q}`

$$ \frac{\text{(I and B) S } \{\text{I}\}}{\{I\} \text{ while B do S } \{ \text{I and (not B)} \} } $$

where I is the loop invariant (the key is to find the loop invariant)

#### Loop Invariant

Characteristics of the loop invariant: I must meet the following conditions:
- $P \Rightarrow I$: the loop invariant must be true initially
- $\{ \text{I and B} \} \text{ S } \{ \text{I} \}$: I is not changed by executing the body of the loop
- $\text{(I and (not B))} \Rightarrow \text{Q}$: if I is true and B is false, Q is implied
- The loop terminates: can be difficult to prove

```
while y != x do y=y+1 {y==x}
I: y <= x
P: y <= x
```
