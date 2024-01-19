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
for (expr1; expr2; expr3){
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



#### Expressions



#### Assignment Statements



#### Logical Pretest Loops


### Axiomatic Semantics

Based on mathematical logic, the original purpose of axiomatic semantics was formal program verification.

An **assertion** before a statement (a *precondition*) states the relationships and constraints among variables that are true at that point in execution.
- An assertion following a statement is a *postcondition*.
- A *weakest precondition* is the least restrictive precondition that will guarantee the postcondition.

In **axiomatic semantics**, the meaning of a specific statement is defined by its precondition and postcondition. The two assertions specify precisely the effect of executing the statement. Axioms or inference rules are defined for each statement type in the language.

#### Form



#### Assignment



#### Sequences



#### Selection



#### Loops



#### Loop Invariant
