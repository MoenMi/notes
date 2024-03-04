# 22 - Smalltalk

## Basics

### Object-Oriented

Everything is an object.

```{image} images/smalltalk-objects.png
:width: 450px
:align: center
```

### GNU Smalltalk

```bash
ssh username@cs-parallel.ua.edu
```

Interactive mode
```Smalltalk
gst
    st> 4+5
    9
    st> 4+5*6
    54
    st> ObjectMemory quit
```
You can also type `CTRL-D` to quit.

### Literals

- Numbers: `12`, `23.4`
- Characters: `$a`, `$A`
- Strings: `'This is a string.'`
- Symbols (strings used for names): `#foo`
- Arrays: `#('three' 'four' 5 6 $Z)`
- Blocks: `[:x | x + 2]` 

### Naming

Names in Smalltalk are a sequence of letters and digits beginning with a letter.

Global variables, class variables, pool dictionaries, and class names should start with an uppercase letter. Instance variables, methods, block arguments, and temporary variables start with a lowercase letter.

Only 6 "keywords" are reserved: `true`, `false`, `nil`, `self`, `super`, `thisContext`.

### Variables

- Temporary variables
- Instance variables
- Class variables
- Pool variables: A **pool variable** is a variable whose scope is a defined subset of classes.
- Global variables (`Smalltalk` dictionary)

### Expression

- A variable name
- A literal
- A message expression
- A block expression

### Messages

- Unary, keyword, and binary messages
- Message chaining, evaluated from left to right
- Unary messages take precedence over binary messages
- Binary messages take precedence over keyword messages
- All binary messages have the same precedence
- Parantheses change the precedence

### Assignment Statement

```Smalltalk
variable := expression
quantity := 19
index :=  initialIndex
index := index + 1
y := quantity sqrt
z := 1 + 2 * 3
f := [:x|x+1]
```

## Collections

- Arrays
- Sets
- Dictionaries

```{image} images/collection-hierarchy.png
:width: 450px
:align: center
```

### Array

```Smalltalk
x := Array new: 20
x at: 1
x at: 1 put: 99
```

Note that the first index is 1.

### Set

```Smalltalk
x := Set new
x add: 5. x add: 7. x add: 'foo'
x add: 5; add: 7; add: 'foo'    "Message Cascading"
x remove: 5
x includes: 7
```

### Dictionary

```Smalltalk
y := Dictionary new
y at: 'name' put: 'John Smith'
y at: 'age' put: 25
y at: 'name'
y at: 'age'
```

## Control Structures

### Selection

```Smalltalk
aBoolean ifTrue: aBlock "evaluates aBlock if aBoolean is true"
aBoolean ifFalse: aBlock "evaluates aBlock if aBoolean is false"
aBoolean ifTrue: trueBlock ifFalse: falseBlock "evaluates trueBlock if aBoolean is true, falseBlock if false"
aBoolean ifFalse: falseBlock ifTrue: trueBlock "evaluates trueBlock if aBoolean is true, falseBlock if false"
```

```Smalltalk
index <= limit
    ifTrue: [total := total + (list at: index)]
```

```Smalltalk
index <= limit
    ifTrue: [total := total + (list at: index)]
    ifFalse: []
```

### Iteration

```Smalltalk
aBooleanBlock whileTrue: loopBlock  "as long as aBooleanBlock evaluates to true, loopBlock is evaluated"
aBooleanBlock whileFalse: loopBlock  "as long as aBooleanBlock evaluates to false, loopBlock is evaluated"
aBooleanBlock whileTrue "repeats evaluating aBooleanBlock until it returns false"
aBooleanBlock whileFalse "repeats evaluating aBooleanBlock until it returns true"
```

```Smalltalk
index := 1.
[index <= list size]
whileTrue: [list at: index put: 0.
            index := index + 1]
```

#### Multiple Iterations

```Smalltalk
n timesRepeat: [
    ...
    repeated statements
    ...
]
```

```Smalltalk
5 timesRepeat: [100 printNl]
```

#### Interval and Iteration

```Smalltalk
anArray := #('one' 'deux' 'drei' 'quatro' 5 6.0).

1 to: 6 do: [:idx | (anArray at: idx) printNl].
```

#### Collection and Iteration

This uses the following form: `aCollection do: aOneArgBlock`.

```Smalltalk
anArray do:[:eachElement | eachElement printNl].
```
