# 36 - Logical

## Prolog Topics Related to Assignment #8

### The Facts

Data
- `commission Mary Smith 300 19000 0.1`
- `commission Floyd Jenkins 500 3000 0.12`
- `commission Rose Harvey 500 20000 0.15`

Predicates
- `commission('Mary', 'Smith', 300, 19000, 0.1)`
- `commission('Floyd', 'Jenkins', 500, 3000, 0.12)`
- `commission('Rose', 'Harvey', 500, 20000, 0.15)`

### The Rules

```prolog
pay(F, L, P) :- commission(F, L, Min, Sales, Crate),
    Sales * Crate > Min,
    P is Sales * Crate.
```

```prolog
pay(F, L, P) :- commission(F, L, Min, Sales, Crate),
    Sales * Crate =< Min,
    P is Min.
```

### Relational and Logical Operators

Numerical comparison operators:
- `=:=`
- `=\=`
- `<`
- `=<`
- `>`
- `>=`

String comparison operators:
- `=`
- `\=`
- `@<`
- `@=<`
- `@>`
- `@>=`

Logical operators:
- `,` is AND
- `;` is OR

### Selection

If A then B else C is written as

```prolog
(A -> B ; C)
```

```prolog
max(X, Y, Z) :-
    ( X =< Y -> Z = Y
    ; Z = X).
```

```prolog
(Length > 0
    -> Avg is Sum / Length
    ; Avg is 0).
```

Multi-way selection:

```prolog
(
    Op='eq', findall([X, Y, Z], (pay(X, Y, Z), Z=:=Ref), List);
    Op='ne', findall([X, Y, Z], (pay(X, Y, Z), Z=\=Ref), List);
    Op='gt', findall([X, Y, Z], (pay(X, Y, Z), Z>Ref), List);
    Op='ge', findall([X, Y, Z], (pay(X, Y, Z), Z>=Ref), List);
    Op='lt', findall([X, Y, Z], (pay(X, Y, Z), Z<Ref), List);
    Op='le', findall([X, Y, Z], (pay(X, Y, Z), Z=<Ref), List)
).
```

### Rules for Queries

```prolog
count(Op, Ref, Count) :- (
    Op=‘eq‘, findall(Z, (pay(X, Y, Z), Z=:=Ref), List),  length(List, Count);
    Op=‘ne‘, findall(Z, (pay(X, Y, Z), Z=\=Ref), List),  length(List, Count);
    Op=‘gt’, findall(Z, (pay(X, Y, Z), Z>Ref), List),  length(List, Count);
    Op=‘ge‘, findall(Z, (pay(X, Y, Z), Z>=Ref), List),  length(List, Count);
    Op=‘lt‘, findall(Z, (pay(X, Y, Z), Z<Ref), List),  length(List, Count);
    Op=‘le‘, findall(Z, (pay(X, Y, Z), Z=<Ref), List),  length(List, Count)
).
```

### `findAll`

- `findAll(Object, Goal, List).`
- `findAll([F, L], salaried(F, L, _), List).` to find the name of all salaried employees 

### Six Queries

- `list(Op, Ref, List).`
- `count(Op, Ref, List).`
- `min(Op, Ref, List).`
- `max(Op, Ref, List).`
- `total(Op, Ref, List).`
- `avg(Op, Ref, List).`
