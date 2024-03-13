# 25 - Smalltalk

## Collections

```{image} images/smalltalk-collections.png
:width: 450px
:align: center
```

Differences among collections:

```{image} images/smalltalk-collections-differences.png
:width: 450px
:align: center
```

### Collection Methods

- `aCollection do: aBlock`
- `aCollection add: newObject`
- `aCollection remove: oldObject`

### Issues with Collections

- Two operations can't be intermingled
- Two collections can't be iterated at the same time

## Streams

```{image} images/streams1.png
:width: 650px
:align: center
```

```{image} images/streams2.png
:width: 650px
:align: center
```

- `atEnd` - Has the final item been consumed?
- `next` - Answer the next item in the stream
- `do:` - Iterate through a stream

### Stream Hierarchy

- `Stream`
    - `PositionableStream`
        - `ReadStream`
        - `WriteStream`
            - `ReadWriteStream`

### PositionableStream

- `position` - Get the current position of the stream
- `position: n` - Set the current position of the stream
- `reset` - Set the position to the front of the collection
- `setToEnd` - Set the position to the end of the collection
- `skip: n` - Skip the next n elements
- `peek` - Answer the next element without moving
- `contents` - Answer the whole contents of the stream
- `upToEnd` - Answer all items up to the stream's end

### ReadStream

```Smalltalk
rs := ReadStream on: 'Mary had a little lamb'.
rs next.
rs upTo: $ .
rs nextLine.
```

### WriteStream

```Smalltalk
rs := WriteStream on: Array new.
nextPut: item           "Put a single item"
nextPutAll: collection  "Put a collection"
next: n put: item       "Put n copies of item"
```

### ReadWriteStream

A `ReadWriteStream` combines `ReadStream` and `WriteStream`.

`ReadWriteStream` answers to the same messages as `ReadStream` and `WriteStream`.

Random access is allowed.

### FileStream

Opening:

```Smalltalk
    f := FileStream open: 'data' mode: #read
    f := FileStream open: 'data' mode: #write
ifFail: aBlock
```

Closing:

```Smalltalk
f close
```

### Reading

- `next` - Answer the next element
- `next: n` - Answer the next n elements as a collection
- `nextLine` - Answer up to the next line delimiter
- `nextMatchFor: anObject` - Check if the next item is `anObject`
- `skip: n` - Skip n items
- `skipTo: item` - Skip items to the next occurrence of `item`
- `skipToAll: aCollection` - Skip items to `aCollection`
- `upTo: item` - Return items up to next occurrences of `item`
- `upToAll: aCollection` - Return items up to `aCollection`

Reading all lines:

```Smalltalk
b := f nextLine.
[f atEnd] whileFalse:
    [
        b displayN1.
        b := f nextLine.
    ].
```

### Writing

- `nextPut: item` - Put a single item
- `nextPutAll: collection` - Put a collection
- `next: n put: item` - Put n copies of item

```Smalltalk
'Enter a binary expresssion: ' display.
expr := stdin nextLine.
tokens:=expr subStrings.
1 to: 3 do: [:index | (tokens at: index) printNl].
a:= (tokens at: 1) asNumber.
b:= (tokens at: 3) asNumber.
((tokens at: 2) = '+') ifTrue: [
        c:=(a+b).
        'The sum is ' display.
        c displayNl.]

```
