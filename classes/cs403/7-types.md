# 7 - Types

## Primitive Types

Almost all programming languages provide a set of **primitive data types**, which are data types not defined in terms of other types. Some primitive data types are reflections of the hardware, while others require only a little non-hardware support for their implementation.

### Integers

Integers are almost always an exact reflection of the hardware, so the mapping is trivial. Languages will often have several integer types. Java has 4 sizes for signed integers: `byte`, `short`, `int`, and `long`.

### Floating Points

Languages for scientific use support at least 2 floating-point types (e.g. `float` and `double`). Floating points are usually designed exactly as the hardware, but not always. See IEEE Floating-Point Standard 754 for more information.

### Complex

Some languages support a complex data type (e.g. C99, Fortran, Python). Each value consists of two floats, representing the real and imaginary parts. Python depicts this type as follows: `(7 + 3i)`.

### Decimal

The decimal data type is built for business applications (e.g. COBOL, C#). A decimal data type stores a fixed number of decimal digits in coded form (BCD). The advantage of this is accuracy, and the disadvantage is wasted memory and limited range.

### Boolean

Booleans, despite only being 1 bit, are often represented as a byte.

### Character

Characters are stored as numeric codings, with the most commonly used coding being ASCII. Another common codding is 16-bit Unicode (UCS-2), which includes characters from most natural languages and was originally used in Java, but is now supported by many other languages. There is also 32-bit Unicode (UCS-4 or UTF-32), which was originally supported by Fortran in 2003.

## Character String Types

### Typical Operatrions

- Assignment/copying
- Comparison (==, >, etc.)
- Catenation
- Substring reference
- Pattern matching

### Character String Type in Certain Languages

In C and C++, strings are not primitive and use `char` arrays and a library of functions that provide string operations.

In SNOBOL4 (a string manipulation language), strings are primitive and support many operations, including elaborate pattern matching.

In Fortran and Python, strings are a primitive type with assignment and several operations.

In Java, C#, Ruby, and Swift, strings are primitive via the `String` class.

Perl, JavaScript, Ruby, and PHP provide built-in pattern matching using regular expressions (regex).

### Character String Length Operations

**Static length** is used in COBOL and Java's `String` class.

**Limited Dynamic Length** is used in C and C++. In these languages, a special character is used to indicate the end of a string's characters, rather than maintaining the length.

**Dynamic Length** is used in SNOBOL4, Perl, and JavaScript.

## Enumeration Types

All possible values, which are named constants, are provided in the definition of enumeration types.

For example, in C#:

```C#
enum days {mon, tue, wed, thu, fri, sat, sun};
```

Some design issues to consider with enums:
- Is an enumeration type constant allowed to appear in more than one type definition, and if so, how is the type of an occurence of that constant checked?
- Are enumeration types coerced to integer?
- Are any other type coerced to an enumeration type?

### Evaluation of Enumeration Types

Enums are an aid to readability, since you don't have to code options as a number.

They are also an aid to reliability, since the compiler can check:
- Operations (e.g. don't allow enums to be added to create nonsense values)
- No enumeration variable can be assigned a value outside its defined range.
- C#, F#, Swift, and Java 5.0 provide better support for enumeration than C++ because enumeration type variables in these languages are not coerced into integer types.

## Array Types

An **array** is a homogeneous aggregate of data elements in which an individual element is identified by its position in the aggregate, relative to the first element.

### Array Design Issues

- What types are legal for subscripts?
- Are subscripting expressions in element refernces range checked?
- When are subscript ranges bound?
- When does allocation take place?
- Are ragged and rectangular multidimensional arrays allowed?
- What is the maximum number of subscripts?
- Can array objects be initialized?
- Are any kind of slices supported?

### Array Indexing

**Indexing** (or subscripting) is a mapping from indices to elements. Most languages used brackets for indexing, but Fortran and Ada uses parentheses. Languages use integers as the index type.

C, C++, Perl, and Fortran do not specify range checking. However, Java, ML, and C# specify range checking.

### Subscript Binding and Array Categories

**Static** subscript ranges are statically bound and storage allocation is static (before run-time). The advantage of this is efficiency.

**Fixed stack-dynamic** subscript ranges are statically bound, but the allocation is done at declaration elaboration time. The advantage of this is space efficiency.

**Fixed heap-dynamic** is similar to fixed stack-dynamic. Storage binding is dynamic but fixed after allocation (i.e. binding is done when requested and storage is allocated from heap, not stack).

**Heap-dynamic** binding of supscript ranges and storage allocation is dynamic and can change any number of times. The advantage is flexibility (arrays can grow and or shrink during program execution).

C and C++ arrays that include the `static` modifier are static, while those without the modifier are fixed stack-dynamic. C and C++ also provide fixed heap-dynamic arrays.

Perl, JavaScript, Python, and Ruby support heap-dynamic arrays.

### Array Initialization

Some languages allow initialization at the time of storage allocation.
- C, C++, Java, Swift, and C# (C# example)
```C#
int list[] = [4, 5, 7, 83];
```
- Character strings in C and C++
```C
char name[] = "freddie";
```
- Array of strings in C and C++:
```C
char *names[] = ["Bob", "Jake", "Joe"];
```
- Java initialization of String objects
```Java
String[] names = ["Bob", "Jake", "Joe"];
```

### Rectangular and Jagged Arrays

A **rectangular array** is a multi-dimensional array in which all of the rows have the same number of elements and all of the columns have the same number of elements.

A **jagged matrix** has rows with varying number of elements, which is possible when multi-dimensional arrays actually appear as arrays of arrays.

### Slices

A **slice** is some substructure of an array. Slices are only useful in arrays that have array operations.

Python example:
```Python
vector = [2, 4, 6, 8, 10, 12, 14, 16]
mat = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
```
- `vector[3:6]` is a three-element array
- `mat[0][0:2]` is the first and second element of the first row of `mat`

Ruby supports slices with the `slice` method: `list.slice(2,2)` returns the third and fourth elements of `list`.

### Implementation of Arrays

An access function maps subscript expressions to an address in the array.

In a single-dimensional array:
```
address(list[k]) = address(list[lower_bound]) + ((k-lower_bound) * element_size)
address(list[k]) = address(list[0]) + k*element_size
```

### Accessing Multi-Dimensional Arrays

There are 2 common methods for accessing two-dimensional arrays:
- Row major order (by rows), which is used in most languages
- Column major order (by columns), which is used in Fortran

## Associative Arrays

An **associative array** is an unordered collection of data elements that are indexed by an equal number of values called **keys**. Associative arrays, also known as dictionaries, are a built-in type in Perl, Python, Ruby, and Swift.

### Associative Arrays in Perl

Names begin with `%`, literals are delimited by parantheses:

```Perl
%hi_temps = ("Mon" => 77, "Tue" => 79, "Wed" => 65, ...);
```

Subscripting is done by using brackets and braces:

```Perl
$hi_temps{"Wed"} = 83;
```

Elements can be removed with `delete`:

```Perl
delete $hi_temps{"Tue"};
```
