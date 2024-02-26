# 19 - ADT

## Parameterized Abstract Data Types

Parameterized ADTs allow designing an ADT that can store any type elements; this is only an issue for static typed languages. These are also known as generic classes.

C++, Java 5.0, and C# 2005 provide support for parameterized ADTs.

### Parameterized ADTs in C++

Classes can be somewhat generic by writing parameterized constructor functions:

```C++
Stack (int size) {
    stk_ptr = new int [size];
    max_len = size - 1;
    top -= 1;
};
```

This `Stack` objects is declared as follows:

```C++
Stack stk(150);
```

The stack element type can be parameterized by making the class a templated class:

```C++
template <class Type>
class Stack {
    private:
        Type *stackPtr;
        const int maxLen;
        int topSub;
    public:
        Stack() {
            stackPtr = new Type[100];
            maxLen = 99;
            topSub -= 1;
        }
        Stack(int size) {
            stackPtr = new Type[size];
            maxLen = size - 1;
            topSub -= 1;
        }
        ...
}
```

This can be instantiated as follows:

```C++
Stack<int> myIntStack;
```

### Parameterized Classes in Java 5.0

- Generic parameters must be classes
- Most common generic types are the collection types, such as `LinkedList` and `ArrayList`
- Eliminate the need to cast objects retrieved
- Eliminate the problem of having multiple types in a structure
- Generic collection classes cannot store primitives
- Indexing is not supported
- Users can define generic classes
- Example of the use of a predefined generic class:

```Java
ArrayList<Integer> myArray = new ArrayList<Integer>();
myArray.add(0, 47); // Put an element with subscript 0 in it
```

```Java
import java.util.*;
public class Stack2<T> {
    private ArrayList<T> stackRef;
    private int maxLen;
    public Stack2() {
        stackRef = new ArrayList<T> ();
        maxLen = 99;
    }
    public void push(T newValue) {
        if (stackRef.size() == maxLen)
        System.out.println(" Error in push – stack is full");
        else
        stackRef.add(newValue);
    }
    ...
}
```

### Parameterized Classes in C# 2005

- Similar to those of Java 5.0, except no wildcard classes
- Predefined for Array, List, Stack, Queue, and Dictionary
- Elements of parameterized structures can be accessed through indexing

## Encapsulation Constructs

Large programs have 2 special needs:
- Some means of organization, other than simply division into subprograms
- Some means of partial compilation (compilation units that are smaller than the whole program)

An obvious solution to this problem: a grouping of subprograms that are logically related into a unit that can be separately compiled (compilation units). Such units are called **encapsulation**.

### Nested Subprograms

Organizing programs by nesting subprogram definitions inside the logically larger subprograms that use them.

Nested subprograms are supported in Python, JavaScript, and Ruby.

### Encapsulation in C

- Files containing one or more subprograms can be independently compiled
- The interface is placed in a **header file**
- `#include` preprocessor specification - used to include header files in applications
- One potential problem is that the linker does not check types between a header and associated implementation

### Encapsulation in C++

- Can define header and code files, similar to those of C
- Or, classes can be used for encapsulation
    - The class is used as the interface (prototypes)
    - The member definitions are defined in a separate file
- **Friends** provide a way to grant access to private members of a class

### C# Assemblies

- A collection of files that appear to application programs to be a single dynamic link library or executable
- A module that can be separately compiled
- A DLL is a collection of classes and methods that are individually linked to an executing program
- C# has an access modifier called `internal`; an `internal` member of a class is visible to all classes in the assembly in which it appears

## Naming Encapsulations

- Large programs define many global names; need a way to divide into logical encapsulations
- A **naming encapsulation** is used to create a new scope for names
- C++ namespaces
    - Can place each library in its own namespace and qualify names used outside with the namespace
    - C# also includes namespaces
- If you don't specify `using namespace std;` in C++, you must use `std::cout`
- Java packages
    - Packages can contain more than one class definition; classes in a package are **partial friends**
    - Clients of a package can use fully qualified name or use the `import` definition
    - If you don't specify `import java.util.*;` or `import java.util.ArrayList;`, you must use `java.util.ArrayList`
- Ruby modules
    - Ruby classes are name encapsulations, but Ruby also has modules
    - Typically encapsulate collections of constants and methods
    - Modules cannot be instantiated or subclassed, and they cannot define variables
    - Methods defined in a module must include the module's name
    - Access to the contents of a module is requested with the `require` method

```Ruby
module MyStuff
    PI = 3.14159265
    def MyStuff.mymethod1(p1)
    ...
    end
    def MyStuff.mymethod2(p2)
    ...
    end
end
```

This module is defined in a file named `myStuffMod` and is imported as such:

```Ruby
require 'myStuffMod'
...
MyStuff.mymethod1(x)
...
```
