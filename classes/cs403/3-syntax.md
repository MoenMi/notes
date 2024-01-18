# 3 - Syntax

- **Syntax**: the form or structure of the expressions, statements, and program units
- **Semantics**: the meaning of the expressions, statements, and program units
- Syntax and semantics provide a language's definition
    - Users of a language definition
        - Initial evaluators
        - Implementers
        - Programmers (users)

### The General Problem of Describing Syntax: Terminology

- A **sentence** is a string of characters over some alphabet
- A **language** is a set of sentences
- A **lexeme** is the lowest level syntactic unit of a language (e.g. `*`, `sum`, `begin`, `12.3`)
- A **token** is a category of lexemes (e.g. identifier)

### The Compilation Process

```{image} images/compilation-process.png
:width: 450px
:align: center
```

- **Recognizers**
    - A recognition device reads input strings over the alphabet of the language and decides whether the input strings belong to the language
    - Example: syntax analysis part of a compiler
        - Detailed discussion of syntax analysis in chapter 4
- **Generators**
    - A device that generates sentences of a language
    - Once can determine if the syntax of a particular sentence is syntactically correct by comparing it to the structure of the generator

## Context-Free Grammars and BNF (Backus-Naur Form)

- **Context-Free Grammars**
    - Developed by Noam Chomsky in the mid-1950s
    - Language generators, meant to describe the syntax of natural languages
    - Define a class of languages called context-free languages
- **Backus-Naur Form (BNF)**
    - Invented by John Backus in 1959 to describe the syntax of Algol 58
    - BNF is equivalent to context-free grammars

### BNF Fundamentals

- In BNF, abstractions are used to represent classes of syntactic structures. They act like syntactic variables (also called *nonterminal symbols*, or just *nonterminals*)
- *Terminals* are lexemes or tokens
- A rule has a left-hand side (LHS), which is a nonterminal, and a right-hand side (RHS), which is a string of terminals and/or nonterminals
- Nonterminals are often enclosed in angle brackets
    - Example of BNF rules:

```
<ident_list> → identifier | identifier, <ident_list>
<if_stmt> → if <logic_expr> then <stmt>
```

- Grammar: a finite non-empty set of rules
- A *start symbol* is a special element of the nonterminals of a grammar

### BNF Rules

- An abstraction (or nonterminal symbol) can have more than one RHS

```
<stmt> → <single_stmt> | begin <stmt_list> end
```

- Syntactic lists can be described using recursion

```
<ident_list> → ident | ident, <ident_list>
```

## Derivation and Parse Tree

A **derivation** is a repeated application of rules, starting with the start symbol and ending with a sentence (made up entirely of terminal symbols)

### Example Grammar and Derivation

Example grammar:

```
<program> → <stmts>
<stmts> → <stmt> | <stmt> ; <stmts>
<stmt> → <var> = <expr>
<var> → a | b | c | d
<expr> → <term> + <term> | <term> - <term>
<term> → <var> | const
```

Example derivation:

```
<program> => <stmts> => <stmt>
                     => <var> = <expr>
                     => a = <expr>
                     => a = <term> + <term>
                     => a = <var> + <term>
                     => a = b + <term>
                     => a = b + const
```

### Derivation Terminology

- Every string of symbols in a derivation is a **sentential form**
- A *sentence* is a sentential form that has only terminal symbols
- A *leftmost derivation* is one in which the leftmost nonterminal in each sentential form is the one that is expanded
- A derivation may be neither leftmost nor rightmost

### Parse Tree

- A hierarchical representation of derivation

```{image} images/parse-tree.JPG
:width: 450px
:align: center
```

## Ambiguity

A grammar is **ambiguous** if and only if it generates a sentential form that has two or more distinct parse trees.

### An Ambiguous Expression Grammar

```
<expr> → <expr> <op> <expr> | const
<op> → / | -
```

What is `8-4/2`?

```{image} images/ambiguous-expression-example.JPG
:width: 600px
:align: center
```

### An Unambiguous Expression Grammar

If we use the parse tree to indicate precedence levels of the operators, we cannot have ambiguity.

```
<expr> → <expr> - <term> | <term>
<term> → <term> / const | const
```

```{image} images/unambiguous-expression-example.JPG
:width: 400px
:align: center
```

### Associativity of Operators

Operator associativity can also be indicated by a grammar.

```
<expr> → <expr> + <expr> | const (ambiguous)
<expr> → <expr> + const | const (unambiguous)
```

```{image} images/operator-associativty-example.JPG
:width: 400px
:align: center
```

### Unambiguous Grammar for Selector

- Java `if-then-else` grammar (this is ambiguous)

```
<if_stmt> → if (<logic_expr>) <stmt>
          | if (<logic_expr>) <stmt> else <stmt>
```

- An unambiguous rule for `if-then-else`

```
<stmt> → <matched> | <unmatched>
<matched> → if (<logic_expr>) <matched> else <matched>
          | a non-if statement
<unmatched> → if (<logic_expr>) <stmt>
            | if (<logic_expr>) <matched> else <unmatched>
```

## Extended BNF

- Optional parts are placed in brackets `[]`
    - `<proc_call> → indent [(<expr_list)]`
- Alternative parts of RHSs are placed inside parentheses and separated via vertical bars
    - `<term> → <term> (+|-) const`
- Repitions (0 or more) are placed inside braces `{}`
    - `<ident> → letter {letter|digit}`

### BNF and EBNF

BNF

```
<expr> → <expr> + <term>
        | <expr> - <expr>
        | <term>
<term> → <term> * <factor>
        | <term> / <factor>
        | <factor>
```

EBNF

```
<expr> → <term> {(+ | -) <term>}
<term> → <factor> {(* | /) <factor>}
```
