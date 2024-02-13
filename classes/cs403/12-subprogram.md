# 12 - Subprograms

## Fundamentals of Subprograms

- Each subprogram has a single entry point
- The calling program is suspended during execution of the called subprogram
- Control always returns to the caller when the called subprogram's execution terminates

### Basic Definitions

A **subprogram definition** describes the interface to and the actions of the subprogram abstraction.
- In Python, function definitions are executable; in all other languages, they are non-executable.
- In Ruby, function definitions can appear either in or outside of class definitions. If outside, they are methods of `Object`. They can be called without an object, like a function.

A **subprogram call** is an explicit request that the subprogram be executed.

A **subprogram header** is the first part of the definition, including the name, the kind of subprogram, and the formal parameters.

The **parameter profile** (a.k.a. **signature**) of a subprogram is the number, order, and types of its parameters.

The **protocol** is a subprogram's parameter profile and, if it's a function, its return type.

A **subprogram declaration** provides the protocol, but not the body, of the subprogram.

Function definitions in C and C++ are often called **prototypes**.

A **formal parameter** is a dummy variable listed in the subprogram header and used in the subprogram.

An **actual parameter** represents a value or address used in the subprogram call statement.

### Actual/Formal Parameter Correspondence

Actual parameters can be bound to formal parameters in one of two ways:
1. Positional: The first actual parameter is bound to the first formal parameter. This is safe and effective.
2. Keyword: The name of the formal parameter to which an actual parameter is to be bound is specified with the actual parameter.
    - *Advantage:* Parameters can appear in any order, thereby avoiding parameter correspondence errors
    - *Disadvantage:* User must know the formal parameter's names

### Formal Parameter Default Values

In certain languages (e.g. C++, Python, Ruby, PHP), formal parameters can have default values (if no actual parameter is passed).

In C++, default parameters must appear last because parameters are positionally associated (no keyword parameters).

### Variable Numbers of Parameters

C# methods can accept a variable number of parameters as long as they are of the same type. The corresponding formal parameter is an array preceded by `params`.

In Ruby, the actual parameters are sent as elements of a hash literal and the corresponding formal parameter is preceded by an asterisk.

In Python, the actual is a list of values and the corresponding formal parameter is a name with an asterisk.

### Procedures and Functions

There are 2 categories of subprograms:
1. **Procedures** are collections of statements that define parameterized computations.
2. **Functions** structurally resemble procedures but are semantically modeled on mathematical functions.
    - They are expected to produce no side effects
    - In practice, program functions have side effects

## Design Issues for Subprograms

- Are local variables static or dynamic?
- Can subprogram definitions appear in other suprogram definitions?
- What parameter passing methods are provided?
- Are parameter types checked?
- If subprograms can be passed as parameters and subprograms can be nested, what is the referencing environment of a passed subprogram?
- Are functional side effects allowed?
- What types of values can be returned from functions?
- How many values can be returned from functions?
- Can subprograms be overloaded?
- Can subprograms be generic?
- If the language allows nested subprograms, are closures supported?

## Local Referencing Environments

Local variables can be stack-dynamic.
- *Advantages:* Support for recursion; Storage for locals is shared among some subprograms
- *Disadvantages:* Allocation/deallocation, initialization time; Indirect addressing; Subprograms cannot be history sensitive

Local variables can be static.
- *Advantages and disadvantages:* Opposite of those of the stack-dynamic

In most contemporary languages, locals are stack dynamic. In C-based languages, locals are stack dynamic by default, but can be declared `static`. The methods of C++, Python, Java, and C# only have stack dynamic locals.

## Parameter-Passing Methods

The following methods exist for passing parameters:
- In mode
- Out mode
- Inout mode

Models of parameter passing:

```{image} images/parameter-passing-models.png
:width: 450px
:align: center
```

Conceptual models of transfer:
- Physically move a value
- Move an access path to a value

### Pass-by-Value (In Mode)

In pass-by-value, the value of the actual parameter is used to initialize the corresponding formal parameter.
- Normally implemented by copying
- Can be implemented by transmitting an access path but not recommended (enforcing write protection is not easy)
- *Disadvantages* (if by physical move): additional storage is required (stored twice) and the actual move can be costly (for large parameters)
- *Disadvantages* (if by access path method): must write-protect in the called subprogram and accesses cost more (indirect addressing)

### Pass-by-Result (Out Mode)

When a parameter is passed by result, no value is transmitted to the subprogram. The corresponding formal parameter acts as a local variable. Its value is transmitted to caller's actual parameter when control is returned to the caller by physical move. This requires extra storage location and copy operations.

This can potentially cause problems:
- `sub(p1, p1)`: whichever formal parameter is last copied back will represent the current value of `p1`
- `sub(list[sub], sub)`: Compute address of `list[sub]` at the beginning of the subprogram or end?

### Pass-by-Value-Result (Inout Mode)

**Pass-by-value-result** is a combination of pass-by-value and pass-by-result. It is sometimes also called **pass-by-copy**. In this mode, formal parameters have local storage.
- *Disadvantages:* same as those of pass-by-value and pass-by-result

### Pass-by-Reference (Inout Mode)

**Pass-by-reference** (a.k.a. **pass-by-sharing**) passes the path to the parameter.
- *Advantage:* Passing process is efficient (no copying and no duplicated storage)
- *Disadvantages*
    - Slower accesses (compared to pass-by-value) to formal parameters
    - Potentials for unwanted side effects
    - Unwanted aliases (access broadened)
    ```
    foo(total, total);
    foo(list[i], list[j]);
    foo(list[i], list)
    ```

### Pass-by-Name (Inout Mode)

**Pass-by-name** uses textual substitution. Formals are bound to an access method at the time of the call, but actual binding to a value or address takes place at the time of a reference or assignment.

Pass-by-name allows flexibility in late binding.

Implementation requires that the referencing environment of the caller is passed with the parameter, so the actual parameter address can be calculated.

### Implementing Parameter-Passing Methods

In most languages, parameter communication takes place through the run-time stack. Pass-by-reference is the easiest to implement, as only the address is placed in the stack.

```{image} images/implementing-parameter-passing-methods.jpg
:width: 450px
:align: center
```

- Function header: `void sub(int a, int b, int c, int d)`
- Function call in main: `sub(w, x, y, z)` (pass `w` by value, `x` by result, `y` by value-result, `z` by reference)

### Parameter Passing Methods of Major Languages

C
- Pass-by-value
- Pass-by-reference is achieved by using pointers as parameters

C++
- A special pointer type called reference type for pass-by-reference

Java
- All non-object parameters are passed by value, so no method can change any of these parameters
- Object parameters are passed by reference

Fortran 95+
- Parameters can be declared to be in, out, or inout mode

C#
- Default method: pass-by-value
- Pass-by-reference is specified by preceding both a formal parameter and its actual parameter with `ref`

PHP
- Very similar to C#, except it uses `&`

Swift
- Default passing method is by value, but pass-by-reference can be specified by preceding the formal with `inout`

Perl
- All actual parameters are implicitly placed in a predefined array named `@_`

Python and Ruby
- Use pass-by-assignment (all data values are objects); the actual is assigned to the formal (pass-by-reference)

### Type Checking Parameters

- Considered very important for reliability
- FORTRAN 77 and original C had no type checking
- Most later languages require type checking
- Relatively new languages Perl, JavaScript, and PHP do not require type checking
- In C89, the choice is made by the user
- In Python and Ruby, variables do not have types (objects do), so parameter type checking is not possible

### Multidimensional Arrays as Parameters

If a multidimensional array is passed to a subprogram and the subprogram is separately compiled, the compiler needs to know the declared size of that array to build the storage mapping function.

In C and C++,
- The programmer is required to include the declared sizes of all but the first subscript in the actual parameter
- This disallows writing flexible subprograms
- Solution: Pass a pointer to the array and the sizes of the dimensions as other parameters; the user must include the storage mapping function in terms of the size parameters

In Java and C#,
- Arrays are objects, they are single-dimensioned, but the elements can be arrays
- Each array inherits a named constant (`length` in Java, `Length` in C#) that is set to the length of the array when the array object is created

### Design Considerations for Parameter Passing

There are 2 important considerations:
1. Efficiency
2. One-way or two-way data transfer

However, these considerations are in conflict
- Good programming suggests limited access to variables outside, which means one-way whenever possible
- But pass-by-reference is more efficient to pass structures of significant size
