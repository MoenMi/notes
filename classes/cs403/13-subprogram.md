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

In C++, generic subprograms are preceded by a `template` clause that lists the generic variables, which can be type names or class names.

```C++
template <class Type>
Type max(Type first, Type second) {
    return first > second ? first : second;
}
```

Java 5.0 has similar support for generic subprograms as C++, but the following differences:
- Generic parameters must be classes
- Generic methods are instantiated just once as truly generic methods
- Restrictions can be specified on the range of classes that can be passed to the generic method as generic parameters
- Wildcard types of generic parameters

```Java
public static <T> T doIt(T[] list) {...}
```
- The para

## User-Defined Overloaded Operators



## Closures



## Coroutines


