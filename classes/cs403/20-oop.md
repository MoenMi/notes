# 20 - OOP

## Object-Oriented Programming

Some languages support procedural and data-oriented programming (e.g. C++), while others support functional programming (e.g. CLOS).

Newer languages do not support other paradigms but use their imperative structures (e.g. Java and C#).

Some languages are pure OOP languages (e.g. Smalltalk and Ruby).

Object-oriented programming languages have 3 major language features:
1. Abstract data types
2. Inheritance - This is the central theme of OOP and the languages that support it
3. Polymorphism

### Inheritance

- Productivity can come from reuse
    - ADTs are difficult to reuse, since they always need to changes
    - All ADTs are independent and at the same level
- Inheritance allows new classes defined in terms of existing ones, i.e. by allowing them to inherit common parts
- Inheritance addresses both of the above concerns (reuse ADTs after minor changes and define classes in a hierarchy)

### Object-Oriented Concepts

- ADTs are usually called **classes**
- Class instances are called **objects**
- Subprograms that define operations on objects are called **methods**
- Calls to methods are called **messages**
- Messages have 2 parts: a method name and the destination object
- A class that inherits is a **derived class**, **subclass**, or **child class**
- The class from which another class inherits is called a **base class**, **superclass**, or **parent class**
- In the simplest case, a class inherits all of the entities of its parent
- Inheritance can be complicated by access controls to encapsulated entities
    - A class can hide entities from its subclasses
    - A class can hide entities from its clients
    - A class can hide entities from its clients while allowing its subclasses to see them
- Besides inheriting methods as is, a class can modify an inherited method
    - The new one **overrides** the inherited one
    - The method in the parent is **overriden**

There are 3 ways a class can differ from its parent:
1. The subclass can add variables and/or methods to those inherited from the parent.
2. The subclass can modify the behavior of one or more of its inherited methods.
3. The parent class can define some of its variables or methods to have private access, which means they will not be visible in the subclass.

There are 2 kinds of variables in a class:
1. **Class variables** - one per class
2. **Instance variables** - one per object

There are 2 kinds of methods in a class:
1. **Class methods** - one per class
2. **Instance methods** - one per object

### Dynamic Binding/Polymorphism

A **polymorphic variable** can be defined to reference (or point to) objects of the class and objects of any of its descendants.

When a class hierarchy includes classes that override methods and such methods are called through a polymorphic variable, the binding to the correct method will be dynamic.

Dynamic binding allows software systems to be more easily extended during both development and maintenance.

An **abstract method** is one that does not include a definition (it only defines a protocol).

An **abstract class** is one that includes at least one virtual method. An abstract class cannot be instantiated.

## Design Issues for Object-Oriented Languages

- Exclusivity of objects?
- Are subclasses subtypes?
- Single and multiple inheritance
- Object allocation and deallocation
- Dynamic and static binding
- Nested classes
- Initialization of objects

### Exclusivity of Objects

- Everything is an object
    - Advantage - elegance and purity
    - Disadvantage - slow operations on simple objects
- Add objects to a complete typing system
    - Advantage - fast operations on simple objects
    - Disadvantage - results in a confusing type stream (two kinds of entities)
- Includes an imperative-style typing system for primitives but make everything else objects
    - Advantage - fast operations on simple objects and a relatively small typing system
    - Disadvantages - still some confusion because of the two type systems

### Are Subclasses Subtypes?

- Does an "as-is" relationship hold between a parent class and an object of the subclass?
    - If a derived class is a parent class, then objects of the derived class must behave the same as the parent class object
- A derived class is a subtype if it has an is-a relationship with its parent class
    - Subclass can only add variables and methods and override inherited methods in "compatible" ways

### Single and Multiple Inheritance

**Multiple inheritance** allows a new class to inherit from two or more classes.
- Disadvantages
    - Language and implementation complexity (in part due to name collisions)
    - Potential inefficiency - dynamic binding costs more with multiple inheritance (but not much)
- Advantages
    - Sometimes it is convenient and valuable

### Allocation and Deallocation of Objects

- From where are objects allocated?
    - If they behave like ADTs, they can be allocated anywhere
        - Allocated from the run-time stack
        - Explicitly create on the heap (via `new`)
    - If they are all heap-dynamic, references can be uniform through a pointer or reference variable
        - Simplifies assignment - dereferencing can be implicit
    - If objects are stack dynamic, there is a problem with regards to subtypes - **object slicing**
- Is deallocation implicit or explicit?

### Dynamic and Static Binding

- Should all binding of messages to methods be dynamic?
    - If none are, you lose the advantages of dynamic binding
    - If all are, it is inefficient
- Maybe the design should allow the user to specify

### Nested Classes

- If a new class is needed by only one class, there is no reason to define so it can be seen by other classes
    - Can the new classes be nested inside the class that uses it?
    - In some cases, the new class is nested inside a subprogram rather than directly in another class
- Other issues
    - Which members of the nesting class should be visible to the nested class and vice versa?

### Initialization of Objects

- Are objects initialized to values when they are created?
    - Implicit or explicit initialization
- How are parent class members initialized when a subclass object is created?

## Support for Object-Oriented Programming in Smalltalk

Smalltalk is a pure OOP language.
- Everything is an object
- All computation is through objects sending messages to objects
- None of the appearances of imperative languages
- All objects are allocated from the heap
- All deallocation is implicit
- Smalltalk classes cannot be nested in other classes

Inheritance in Smalltalk:
- A Smalltalk subclass inherits all of the instance variables, instance methods, and class methods of its superclass
- All subclasses are are subtypes (nothing can be hidden)
- No multiple inheritance

Dynamic binding in Smalltalk:
- All binding of messages to methods is dynamic
    - The process is to search the object to which the message is sent for the method; if not found, search the superclass, etc. up to the system class (`object`) which has no superclass
- The type checking in Smalltalk is dynamic and the only type error occurs when a message is sent to an object that has no matching method

Evaluation of Smalltalk:
- The syntax of the language is simple and regular
- Good example of power provided by a small language
- Slow compared with conventional compiled imperative languages
- Dynamic binding allows type errors to go undetected until run time
- Introduced the graphical user interface
- Greatest impact: advancement of OOP

## Support for Object-Oriented Programming in C++

General characteristics:
- Evolved from C and SIMULA 67
- Among the most widely used OOP languages
- Mixed typing systems
- Elaborate access controls to class entities

Inheritance:
- A class need not be the subclass of any class
- Access controls for members are
    - `private` - visible only in the class and friends
    - `public` - visible in subclasses and clients
    - `protected` - visible in the class and in subclasses, but not clients
- In addition, the subclassing process can be declared with access controls (private or public), which define potential changes in access by subclasses
    - Private derivation - inherited public and protected members are private in the subclasses
    - Public derivation - public and protected members are also public and protected in subclasses

```C++
class base_class {
    private:
        int a;
        float x;
    protected:
        int b;
        float y;
    public:
        int c;
        float z;
};

class subclass_1 : public base_class { … };
// In this one, b and y are protected and
// c and z are public

class subclass_2 : private base_class { … };
// In this one, b, y, c, and z are private,
// and no derived class has access to any
// member of base_class
```

### Reexportation

A member that is not accessible in a subclass (because of private derivation) can be declared to be visible there using the scope resolution operator `::`:

```C++
class subclass_3 : private base_class {
    public:
        base_class :: c;
    ...
}
```

One motivation for using private derication is when a class provides members that must be visible, so they are defined to be public members; a derived class adds some new members, but does not want its clients to see the members of the parent class, even though they had to be public in the parent class definition.

### Multiple Inheritance

Multiple inheritance is supported. If there are 2 inherited members with the same name, they can both be referenced using the scope resolution operator `::`.

```C++
class Thread { ... }
class Drawing { ... }
class DrawThread : public Thread, public Drawing { ... }
```

### Dynamic Binding

A method can be made `virtual`, which means that they can be called through polymorphic variables and dynamically bound to messages.

A pure virtual function has no definition at all.

A class that has at least one pure virtual function is an **abstract class**.

```C++
class Shape {
    public:
        virtual void draw() = 0;
    ...
};
class Circle : public Shape {
    public:
        void draw() { ... }
    ...
};
class Rectangle : public Shape {
    public:
        void draw() { ... }
    ...
};
```

```C++
Circle* circ = new Circle;
Rectangle* rect = new Rectangle;
Shape* ptr_shape;
ptr_shape = circ;   // Points to a Circle
ptr_shape->draw();  // Dynamically bound to draw in Circle
rect->draw();       // Statically bound to draw in Rectangle
```

### Evaluation

- C++ provides extensive access controls, unlike Smalltalk.
- C++ provides multiple inheritance
- In C++, the programmer must decide at design time which methods will be statically bound and which must be dynamically bound
    - Static binding is faster
