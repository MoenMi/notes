# 13 - Subprograms

## Parameters That Are Subprogram Names

It is sometimes convenient to pass subprogram names as parameters. However, this can raise the following issues:
1. Are parameter types checked?
2. What is the correct referencing environment for a subprogram that was sent as a parameter?

### Referencing Environment

**Shallow binding**: The environment of the call that enacts the passed subprogram. This is the most natural for dynamic-scoped languages.

**Deep binding**: The environment of the definition of the passed subprogram. This is most natural for static-scoped languages.

**Ad hoc binding**: The environment of the call statement that passed the subprogram.

An example in JavaScript:
```JavaScript
function sub1() {
    var x;
    function sub2() {
        alert(x);
    };
    function sub3() {
        var x;
        x = 3;
        sub4(sub2);
    };
    function sub4(subx) {
        var x;
        x = 4;
        subx();
    };
    x = 1;
    sub3();
}
```

## Calling Subprograms Indirectly

Indirect calls to subprograms usually occur when there are several possible subprograms to be called and the correct one on a particular run of the program is not known until execution (e.g. event handling and GUIs).

In C and C++, such calls made through function pointers.

In C#, method pointers are implemented as objects called **delegates**.
- A delegate declaration:
    ```C#
    public delegate in Change(int x);
    ```
- This delegate type, named `Change`, can be instantiated with any method that takes an `int` value
- Consider the method `static int fun1(int x) {...}`. We can instantiate it with
    ```C#
    Change chgfun1 = new Change(fun1);
    ```
- Now, `fun1` can be called with `chgfun1`
- A delegate can store more than one address, which is called a **multicast delegate**.

## Overloaded Subprograms

An **overloaded subprogram** is one that has the same name as another subprogram in the same referencing environment. Every version of an overloaded subprogram has a unique protocol.

C++, Java, C#, and Ada include predefined overloaded subprograms (e.g. constructors). These languages also allow users to write multiple versions of subprograms with the same name

## Generic Subprograms

A **generic** or **polymorphic subprogram** takes parameters of different types on different activations.

A subprogram that takes a generic parameter that is used in a type expression that describes the type of the parameters of the subprogram provides **parametric polymorphism**.
- This is a cheap, compile-time substitute for dynamic binding

### C++

In C++, generic subprograms are preceded by a `template` clause that lists the generic variables, which can be type names or class names.

```C++
template <class Type>
Type max(Type first, Type second) {
    return first > second ? first : second;
}
```

### Java

Java 5.0 has similar support for generic subprograms as C++, but the following differences:
- Generic parameters must be classes
- Generic methods are instantiated just once as truly generic methods
- Restrictions can be specified on the range of classes that can be passed to the generic method as generic parameters
- Wildcard types of generic parameters

```Java
public static <T> T doIt(T[] list) {...}
```

The parameter in the example above is an array of generic elements, where `T` is the name of the type. This function can be called as follows:

```Java
doIt<String>(myList);
```

Generic parameters can have bounds:

```Java
public static <T extends Comparable> T doIt (T[] list) { ... }
```

In the example above, the generic type `T` must be of a class that inherits the `Comparable` interface.

#### Wildcard Types

`Collection<?>` is a wildcard type for collection classes:

```Java
void printCollection(Collection<?> c) {
    for (Object e: c) {
        System.out.println(e);
    }
}
```

The example above works for any collection class.

### C#

C# 2005 supports generic methods that are similar to those of Java 5.0. One key difference, however, is that actual type parameters in a call can be omitted if the compiler can infer the unspecified type. Additionally, C# does not support wildcard types.

### F#

F# infers a generic type if it cannot determine the type of a parameter or the return type of a function. This is called **automatic generalization**.

Functions can also be defined to have generic parameters:

```F#
let printPair (x: 'a) (y: 'a) =
    printfn "%A %A" x y
```

- `A%` is a format code for any type
- These parameters are not type contrained

If parameters of a funtion are used with arithmetic operators, they are type constrained, even if the parameters are specified to be generic.

Because of type inferencing and the lack of type coercions, F# generic functions are far less useful than those of C++, Java 5.0, and C# 2005+.

## User-Defined Overloaded Operators

Operators can be overloaded in Ada, C++, Python, and Ruby.

```Python
def __add__(self, second):
    return Complex(self.real + second.real,
                   self.imag + second.imag)
```

The Python example above can be called with with either `x + y` or `x.__add__(y)`.

## Closures

A **closure** is a subprogram and the referencing environment where it was defined.
- The referencing environment is needed if the subprogram can be called from any arbitrary place in the program
- A static-scoped language that does not permit nested subprograms doesn't need closures
- Closures are only needed if a subprogram can access variables in nesting scopes and it can be called from anywhere
- To support closures, an implementation may need to provide unlimited extent to some variables (because a subprogram may access a nonlocal variable that is normally no longer alive)

A standard language that does not permit nested subprograms doesn't need closures:

```C++
#include <stdio.h>

int x = 10;
int f() {
    return x;
}
int g() {
    int x = 20;
    return x;
}
int main() {
    printf("%d\n", g());
    return 0;
}
```

### JavaScript

```JavaScript
function init() {
    var name = 'Mozilla';
    function displayName() {
        alert(name);
    }
    displayName();
}
init()
```

```JavaScript
function makeFunc() {
    var name = 'Mozilla';
    function displayName() {
        alert(name);
    }
    return displayName;
}

var myFunc = makeFunc();
myFunc();
```

```JavaScript
function makeAdder(x) {
    return function(y) { return x + y; }
}
...
var add10 = makeAdder(10);
var add5 = makeAdder(5);
document.write("add 10 to 20: " + add10(20) + "<br />");
document.write("add 10 to 20: " + add10(20) + "<br />");
```

The closure in the example above is the anonymous function returned by `makeAdder`.

### C#

We can write the same closure in C# using a nested anonymous delegate.

`Func<int, int>` (the return type) specifies a delegate that takes an `int` as a parameter and returns `int`:

```C#
static Func<int, int> makeAdder(int x) {
    return delegate(int y) { return x + y; };
}
Func<int, int> Add10 = makeAdder(10);
Func<int, int> Add5 = makeAdder(5);
...
Console.WriteLine("Add 10 to 20: {0}", Add10(20));
Console.WriteLine("Add 5 to 20: {0}", Add5(20));
```

## Coroutines

A **coroutine** is a subprogram that has multiple entries, depending on when it is called. This is supported directly in Lua.

Coroutines are also called **symmetric control**: caller and called are on a more equal basis.

A coroutine call is named a **resume**.

The first resume of a coroutine is to its beginning, but subsequent calls enter at the point just after the last executed statement in the coroutine.

Coroutines repeatedly resume each other, possibly forever.

Coroutines provide **quasi-concurrent execution** of program units (the coroutines); their execution is interleaved, but not overlapped.

Possible execution controls:

```{image} images/execution-control1.png
:width: 300px
:align: center
```

```{image} images/execution-control2.png
:width: 300px
:align: center
```

Possible execution controls with loops:

```{image} images/execution-control3.png
:width: 300px
:align: center
```
