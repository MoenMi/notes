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

```{image} images/.png
:width: 450px
:align: center
```

## Implementing Subprograms with Stack-Dynamic Local Variables


