# 23 - Smalltalk

## Smalltalk Rules

1. Everything is an object.
2. Every object is an instance of a class.
3. Every class has a superclass.
4. Everything happens by sending messages.
5. Method lookup follows the inheritance chain.
6. Every class is an instance of a metaclass.
7. The metaclass hierarchy parallels the class hierarchy.
8. Every metaclass inherits from Class and Behavior.
9. Every metaclass is an instance of Metaclass.
10. The metaclass of Metaclass is an instance of Metaclass.

```{image} images/class-metaclass.png
:width: 450px
:align: center
```

## OOP in Smalltalk

### Creating a Class

```Smalltalk
Object subclass: Account [
    | balance |
    <comment:
        'I represent a place to deposit and withdraw money'>
]
```

### Add a class method

```Smalltalk
Account class extend [
    new [
        | r |
        <category: 'instance creation'>
        r := super new.
        r init.
        ^r
    ]
]
```

### Add an instance method

```Smalltalk
Account extend [
    init [
        <category: 'initialization'>
        balance := 0
    ]
]
```

```Smalltalk
Account extend [
    printOn: stream [
        <category: 'printing'>
        super printOn: stream.
        stream nextPutAll: 'with balance: '.
        balance printOn: stream
    ]
]
```

```Smalltalk
Account extend [
    spend: amount [
        <category: 'moving money'>
        balance := balance - amount
    ]
    deposit: amount [
        <category: 'moving money'>
        balance := balance + amount
    ]
]
```

### Put everything together and testing

See `account.st`. You can use `gst account.st -` for testing, or,

```bash
gst
st> FileStream fileIn: 'account.st'
```

### Creating a subclass

```Smalltalk
Account subclass: Savings [
    | interest |
    init [
        <category: 'initialization'>
        interest := 0
        ^super init
    ]
    interest: amount [
        interest := interest + amount
        self deposit: amount
    ]
    clearInterest [
        | oldinterest |
        oldinterest := interest.
        interest := 0.
        ^oldinterest
    ]
]
```

```Smalltalk
Account subclass: Checking [
    | checknum checksleft history |
]
```

### Method with a Block

```Smalltalk
checksOver: amount do: aBlock [
    history keysAndValuesDo: [:key :value |
        (value > amount)
            ifTrue: [aBlock value: key]
    ]
]
```

```Smalltalk
checksOver: amount do: aBlock [
    | chosen |
    chosen := history select: [:amt | amt > amount].
    chosen keysDo: aBlock
]
```

## Testing

See `test.st`.

```Smalltalk
mycheck := Checking new.
mycheck deposit: 250.
mycheck newChecks: 100 count: 40.
mycheck writeCheck: 10.
mycheck writeCheck: 52.
mycheck writeCheck: 15.
mycheck printChecks.
(mycheck check: 101) printNl. 
mycheck checksOver: 1 do: [:x | x printNl].
mycheck checksOver: 17 do: [:x | x printNl].
mycheck checksOver: 200 do: [:x | x printNl].
```
