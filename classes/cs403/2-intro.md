# 2 - Introduction

## Programming Domains

- Scientific applications
    - Large numbers of floating-point computations; use of arrays
    - Fortran
- Bussiness applications
    - Produce reports, use decimal numbers and characters
    - COBOL
- Artificial intelligence
    - Symbols rather than numbers manipulated; use of linked lists
    - LISP
- Systems programming
    - Need efficiency because of continuous use
    - C
- Web software
    - Eclectic collection of languages: markup (e.g. HTML), scripting (e.g. PHP), general-purpose (e.g. Java)

## Language Evaluation Criteria

- **Readability**: the ease with which programs can be read and undersstood
- **Writability**: the ease with which a language can be used to create programs
- **Reliability**: conformance to specificiations (i.e. performs to specifications)
- **Cost**: the ultimate total cost

### Readability

- Overall simplicity
    - A manageable set of features and constructs
    - Minimal feature multiplicity
    - Minimal operator overloading
- Orthogonality
    - A relatively small set of primitive constructs can be combined in a relatively small number of ways
    - Every possible combination is legal
- Data types
    - Adequate predefined data types
- Syntax considerations
    - Identifier forms: flexible composition
    - Special words and methods of forming compound statements
    - Form and meaning: self-descriptive constructs, meaningful keywords

### Writability

- Simplicity and orthogonality
    - Few constructs, a small number of primitives, a small set of rules for combining them
- Support for abstraction
    - The ability to define and use complex structures or operations in ways that allow details to be ignored
- Expressivity
    - A set of relatively convenient ways of specifying operations
    - Strength and number of operators and predefined functions

### Reliability

- Type checking
    - Testing for type errors
- Exception handling
    - Intercept run-time errors and take corrective measures
- Aliasing
    - Presence of two or more distinct referencing methods for the same memory location
- Readability and writability
    - A language that does not support "natural" ways of expressing an algorithm will require the use of "unnatural" approaches, and hence reduced readability

### Cost

- Training programmers to use the language
- Writing programs (closeness to particular applications)
- Executing programs
- Reliability: poor reliability leads to high costs
- Maintaining programs

### Other Evaluation Criteria

- Portability
    - The ease with which programs can be moved from one implementation to another
- Generality
    - The applicability to a wide range of applications
- Well-definedness
    - The completeness and precision of the language's official definition

## Language Design Trade-Offs

- Reliability vs. cost of execution
    - Example: Java demands all references to array elements be checked for proper indexing, which leads to increased execution costs
- Readability vs. writability
    - Example: APL provides many powerful operators (and a large number of new symbols), allowing complex computations to be written in a compact program but at the cost of poor readability
- Writability (flexibility) vs. reliability
    - Example: C++ pointers are powerful and very flexible but unreliable

## Implementation Methods

- Compilation
    - Programs are translated into machine language; includes JIT systems
    - Use: Large commercial applications
- Pure Implementation
    - Programs are interpreted by another program known as an interpreter
    - Use: Small programs or when efficiency is not an issue
- Hybrid Implementation Systems
    - A compromise between compilers and true interpreters
    - Use: Small and medium systems when efficiency is not the first concern

### Layered View of Computer

The operating system and language implementation are layered over machine interface of a computer.

```{image} images/layered-view-of-computer.png
:width: 450px
:align: center
```

### Compilation

- Translate high-level program (source language) into machine code (machine language)
- Slow translation, fast execution
- Compilation process has several phases:
    - Lexical analysis: converts characters in the source program into lexical units
    - Syntax analysis: transforms lexical units into *parse trees* which represent the sytactic structure of the program
    - Semantics analysis: generate intermediate code
    - Code generation: machine code is generated

```{image} images/compilation-process.png
:width: 450px
:align: center
```

### Pure Implementation

- No translation
- Easier implementation of many source level debugging operations (run-time errors can easily and immediately be displayed)
- Slower execution (10 to 100 times slower than compiled programs)
- Often requires more space
- Now rare for traditional high-level languages
- Significant comeback with some Web scripting languages (e.g. JavaScript, PHP)

```{image} images/pure-implementation-process.png
:width: 450px
:align: center
```

### Hybrid Implementation Systems

- A compromise between compilers and pure interpreters
- A high-level language program is translated to an intermediate language that allows easy implementation
- Faster than pure implementation
- Example
    - Perl programs are partially compiled to detect errors before interpretation
    - Initial implementations of Java were hybrid; the intermediate form, byte code, provides portability to any machine that has a byte code interpreter and a run-time system (together, these are called *Java Virtual Machine*)

```{image} images/hybrid-implementation-process.png
:width: 450px
:align: center
```

#### Just-in-Time Implementation Systems

- Initially translate programs to an intermediate language
- Then compile the intermediate language of the subprograms into machine code when they are called
- Machine code version is kept for subsequent calls
- JIT systems are widely used for Java programs
- .NET languages are implemented with a JIT system
- In essence, JIT systems are delayed compilers
