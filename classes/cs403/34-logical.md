# 34 - Logical

## Introduction

Programs in logic languages are **declarative** rather than **procedural**:
- Only specification of *results* are stated (not detailed *procedures* of producing them)

Programs are expressed in a form of symbolic logic.

A logical inferencing process is used to produce results.

### Symbolic Logic

Logic which can be used for the basic needs of formal logic:
- Express propositions
- Express relationships between propositions
- Describe how new propositions can be inferred from other propositions

Particular form of sybolic logic used for logic programming called **(first order) predicate calculus**.

### Propositions and Object Repesentation

A **proposition** is a logical statement that may or may not be true.
- Consists of objects and relationships of objects to each other

For example: `parent(bob, jake)`

Objects in propositions are represented by simple terms: either constants or variables.
- **Constant**: a symbol that represents an object
- **Variable**: a symbol that can represent different objects at different times
    - This is different from variables in imperative languages

For example:
- `parent(bob, jake)`
- `parent(x, jake)`
- `parent(bob, y)`
- `parent(x, y)`

### Compound Terms

**Atomic propositions** are compound terms.

**Compound term**: one element of a mathematical relation, written like a mathematical function

Compound terms are composed of two parts:
- **Functor**: function symbol that names the relationship
- Ordered list of parameters (tuple)

For example:
- `student(jon)`
- `like(seth, OSX)`
- `like(nick, windows)`
- `like(jim, linux)`

### Forms of a Proposition

Propositions can be stated in two forms:
- **Fact**: proposition is assumed to be true
- **Query**: truth of proposition is to be determined

Compound proposition:
- Have two or more atomic propositions
- Propositions are connected by operators

### Logical Operators

| Name | Symbol | Example | Meaning |
| - | - | - | - |
| negation | $\neg$ | $\neg$ a | not a |
| conjunction | $\cap$ | a $\cap$ b | a and b |
| disjunction | $\cup$ | a $\cup$ b | a or b |
| equivalence | $\equiv$ | a $\equiv$ b | a is equivalent to b |
| implication | $\supset$ <br> $\subset$ | a $\supset$ b <br> b $\subset$ a | a implies b <br> b implies a |

### Quantifiers

| Name | Symbol | Example | Meaning |
| - | - | - | - |
| universal | $\forall$ | $\forall$ X.P | For all X, P is true |
| existential | $\exists$ | $\exists$ X.P | There exists a value of X such that P is true |

### Clausal Form

Too many ways to state the same thing. Use a standard form for propositions.

**Clausal form**:
- $B_1 \cup B_2 \cup \dots \cup B_n \subset A_1 \cap A_2 \cap \dots \cap A_m$
- Means if every $A$ is true, then at least one $B$ is true

**Antecedent**: right side

**Consequent**: left side

For example: `likes(bob, trout)` $\subset$ `likes(bob, fish)` $\cap$ `fish(trout)`

## A Brief Introduction to Predicate Calculus



## Predicate Calculus and Proving Theorems



## An Overview of Logic Programming


