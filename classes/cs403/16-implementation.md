# 16 - Subprogram Implementation 

## Nested Subprograms

Some non-C-based static-scoped languages (e.g. Fortran 95+, Ada, Python, JavaScript, Ruby, and Swift) use stack-dynamic local variable and allow subprograms to be nested.

All variables that can be non-locally accessed reside in some activation record instance in the stack.

The process of locating a non-local reference:
1. Find the correct activation record instance
2. Determine the correct offset within the activation record instance

### Locating a Non-Local Refernce

To find the correct activation record instance:
- Static semantic rules guarantee that all non-local variables that can be referenced have been allocated in some activation record instance that is on the stack when the reference is made

### Static Scoping

A **static chain** is a chain is a chain of static links that connects certain activation record instances.

The **static link** is an activation record instance for subprogram A points to the activation record instance of an activation of A's static parent.

The static chain from an activation record instance connects it to all of its static ancestors.

`Static_depth` is an integer associated with a static scope whose value is the depth of nesting of that scope.

The `chain_offset` or `nesting_depth` of a nonlocal reference is the difference between the static_depth of the reference and that of the scope when it is declared.

A reference to a variable can be represented by the pair `(chain_offset, local_offset)`, where `local_offset` is the offset in the activation record of the variable being referenced.

Example in JavaScript:
```JavaScript
function main() {
    var x;
    function bigsub() {
        var a, b, c;
        function sub1() {
            var a, d;
            a = b + c;
        }
        function sub2(x) {
            var b, e;
            function sub3() {
                var c, e;
                sub1();
                e = b + a;
            }
            sub3();
            a = d + e;
        }
        sub2(7);
    }
    bigsub();
}
```

Note that `main` calls `bigsub`, which calls `sub2`, which calls `sub3`, which calls `sub1`.

```{image} images/stack-contents.jpg
:width: 450px
:align: center
```

### Static Chain Maintenance

At the call,
- The activation record instance must be built
- The dynamic link is just the old stack top pointer
- The static link must point to the most recent ARI of the static parent
    - There are 2 methods:
    1. Search the dynamic chain
    2. Treat subprogram calls and definitions like variable references and definitions

Problems with the evaluation of static chains:
- A nonlocal reference is slow if the nesting depth is large
- Time-critical code is difficult:
    - Costs of nonlocal references are difficult to determine
    - Code changes can change the nesting depth, and therefore the cost

## Blocks

**Blocks** are user-specified local scopes for variables.

An example in C:
```C
{int temp;
 temp = list[upper];
 list[upper] = list[lower];
 list[lower] = temp;
}
```

The lifetime of `temp` in the above example begins when control enters the block.

An advantage of using a local variable like `temp` is that it cannot interfere with any other variable with the same name.

### Implementing Blocks

There are 2 methods for implementing blocks:

1. Treat blocks as parameter-less subprograms that are always called from the same location.
    - Every block has an activation record; an instance is created every time the block is executed
2. Since the maximum storage required for a block can be statically determined, this amount of space can be allocated after the local variables in the activation record

Implementing method 2:
```C++
void main() {
    int x, y, z;
    while (...) {
        int a, b, c;
        ...
        while (...) {
            int d, e;
            ...
        }
    }
    while (...) {
        int f, g;
        ...
    }
    ...
}
```

```{image} images/implementing-blocks.png
:width: 450px
:align: center
```

## Implementing Dynamic Scoping

**Deep access**: Non-local references are found by searching the activation record instances on the dynamic chain.
- Length of chain cannot be determined statically
- Every activation record instance must have variable names

**Shallow access**: Put locals in a central place.
- One stack for each variable name
- Central table with an entry for each variable name

### Using deep access to implement dynamic scoping

```C++
void sub3() {
    int x, z;
    x = u + v;
    ...
}
void sub2() {
    int w, x;
    ...
}
void sub1() {
    int v, w;
    ...
}
void main() {
    int v, u;
    ...
}
```

```{image} images/stack-contents-2.png
:width: 450px
:align: center
```

### Using shallow access to implement dynamic scoping

This uses the same code snippet as the previous example:

```{image} images/stack-cells.jpg
:width: 450px
:align: center
```
