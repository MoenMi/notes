# 14 - Subprogram Implementation

## The General Semantics of Calls and Returns

The subprogram call and return operations of a language are together called its **subprogram linkage**.

General semantics of calls to a subprogram:
- Parameter passing methods
- Stack-dynamic allocation of local variables
- Save the execution status of calling program
- Transfer of control and arrange for the return
- If subprogram nesting is supported, access to nonlocal variables must be arranged

General semantics of subprogram returns:
- Out mode and inout mode parameters must have their values returned
- Deallocation of stack-dynamic locals
- Restore the execution status
- Return control to the caller

## Implementing "Simple" Subprograms

Subprograms cannot be nested and all local variables are static.

Call semantics:
- Save the execution status of the caller
- Compute and pass the parameters
- Pass the return address to be called
- Transfer control to the called

Return semantics:
- If pass-by-value-result or pass-by-result parameters are used, move the current values of those parameters to their corresponding actual parameters
- If it is a function, move the functional value to a place the caller can get it
- Restore the execution status of the caller
- Transfer control back to the caller

Required storage:
- Status information
- Parameters
- Return address
- Return value for functions
- Temporaries

Subprograms are implemented with 2 separate parts: the actual code and the non-code part (local variables and data that can change).

The format, or layout, of the non-code part of an executing subprogram is called an **activation record**.

An **activation record instance** is a concrete example of an activation record (the collection of data for a particular subprogram activation).

### An Activation Record for "Simple" Subprograms

```{image} images/activation-record-simple.png
:width: 450px
:align: center
```

### Code and Activation Records of a Program with "Simple" Subprograms

```{image} images/code-activation-record.png
:width: 200px
:align: center
```

## Implementing Subprograms with Stack-Dynamic Local Variables

Using stack-dynamic local variables to implement subprograms involves a much more complex activation record.
- The compiler must generate code to cause implicit allocation and deallocation of local variables
- Recursion must be supported (adds the possibility of multiple simultaneous activations of a subprogram)

### Activation Record

```{image} images/stack-dynamic-activation-record.png
:width: 650px
:align: center
```

- The activation record format is static, but its size may be dynamic.
- The **dynamic link** points to the base of the activation record instance of the caller.
- An activation record instance is dynamically created when a subprogram is called.
- Activation record instances reside on the run-time stack.
- The **Environment Pointer (EP)** must be maintained by the run-time system. It always points to the base of the activation record instance of the currently executing program unit.

An example C Function:

```C
void sub(float total, int part) {
    int list[5];
    float sum;
    ...
}
```

```{image} images/c-activation-record.jpg
:width: 300px
:align: center
```

### Revised Semantic Call/Return Actions

Caller actions:
- Create an activation record instance
- Save the execution status of the current program unit
- Compute and pass the parameters
- Pass the return address to the called
- Transfer control to the called

Prologue actions of the called:
- Save the old EP in the stack as the dynamic link and create the new value
- Allocate local variables

Epilogue actions of the called:
- If there are pass-by-value-result or out-mode parameters, the current values of those parameters are moved to the corresponding actual parameters
- If the subprogram is a function, its value is moved to a place accessible to the caller
- Restore the stack pointer by setting it to the value of the current EP-1 and set the EP to the old dynamic link
- Restore the execution status of the caller
- Transfer control back to the caller
