# 6 - Variables

A **variable** is an abstraction of a memory cell. They can be characterized as a sextuple of attributes:
- Name
- Address
- Value
- Type
- Lifetime
- Scope

## Name

Variables are *case sensitive* in C-based languages, but typically aren't in other languages. The disadvantage of case sensitivity is that names that look similar can be different.

Variable names also must conform to *length* requirements. In some languages, only the first X characters in a variable name are significant.

Some languages use *special characters* in their variable names.
- In PHP, all variables must begin with `$`.
- In Perl, all variables begin with special characters that denote the type.
- In Ruby, `@` and `@@` determine instance vs. class variables.

*Special words* are another common feature of languages:
- A *keyword* is a word that is special only in certain contexts.
- A *reserved word* is a special word that cannot be used in a user-defined name.

## Address

The *address* refers to the memory location in which the variable is associated.
- This may differ at different points in execution.
- If 2 variable names can be used to access the same memory location, they are called **aliases**.
    - Aliases are harmful for readability.

## Value

The *value* of a variable is the contents of the location with which the variable is associated.
- The *l-value* of a variable is its address.
- The *r-value* of a variable is its value.

## Type

The *type* of a variable determines the range of values of variables and the set of operations that are defined for variables of that type; in the case of floating-point, the type also determines the precision.

### The Concept of Binding

A **binding** is an association between an entity and an attribute, such as a variable and its type or value. **Binding time** is the time at which a binding takes place.

A binding is **static** if it first occurs before run time and remains unchanged throughout program execution. A binding is **dynamic** if it first occurs during execution or can change during execution of the program.

### Type Binding

If static, a type may be specified by either an explicit or an implicit declaration.

An **explicit declaration** is a program statement used for declaring the types of variables. An **implicit delcaration** is a default mechanism for specifying types of variables through default conventions, rather than declaration statements.

Some languages use *type inferencing* when determining variable types (no type is given, variable takes type of initial value).

Some languages use **dynamic type binding** (JavaScript, Python, Ruby, PHP). This is flexible, but at a high-cost.

## Lifetime

The **lifetime** of a variable is the time during which it is bound to a particular memory cell.

Variables can have a variety of lifetimes:
- **Static** variables are bound to the same memory cell during execution, making them more efficient but less flexible.
- **Stack-dynamic** variables have storage bindings that are created when their declaration statements are *elaborated* (i.e. when the executable code associated with it is executed). This allows recursion and conserves storage, but creates overhead with allocation and deallocation.
- **Explicit heap-dynamic** variables are allocated and deallocated by explicit directives, specified by the programmer (`new`), which take effect during execution. These are referenced through pointers, references, or objects (Java). These allow dynamic storage management but are inefficient and unreliable.
- **Implicit heap-dynamic** variables are allocated and deallocated by assignment statements. This is flexible but inefficent.

## Scope

The **scope** of a variable is the range of statements over which it is visible.

The **local variables** of a program unit are those that are declared in that unit.

The **nonlocal variables** of a program unit are those that are visible in the unit but not declared there.

**Global variables** are a special category of nonlocal variables.

### Static Scope

In a **static scope**, the compiler must find the declaration of a variable to connect a name reference to a variable.

The search process: Search declarations, first locally, then in increasingly larger scopes until one is found with the name. Enclosing static scopes are called **static ancestors**, with the nearest static scope being the **static parent**.

Variables can be hidden from a unit by having a closer variable with the same name.

### Declaration Order/Position

C99, C++, Java, and C# allow variable declarations to appear anywhere a statement can appear.

In C++, Java, and C#, variables can be declared in `for` statements

### Dynamic Scope

A **dynamic scope** is based on calling sequences of program units, not their textual layout. References to variables are connected to declarations by searching back through the chain of subprogram calls that forced execution to that point.
