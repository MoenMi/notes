# 29 - Functional

## Characters & Character Sets

- `#\a`, `#\A`, `#\(`
- `#\space`, `#\newline`
- `char-set:alphanumeric`
- `char-set:whitespace`
- `(char-set-member? alphanumeric R)` - Checks is `R` is in `char-set:alphanumeric`

## Strings

- `"abc"`, `"This is a string"`
- `(string-length "The length")`
- `(string=? string1 string2)`
- `(string-ci=? string1 string2)` - case insensitive
- `(string-capitalize string)` - capitalize the first letter
- `(string-ref string k)`
- `(substring string start end)`
- `(string-append string ...)`

## Ports

- A **port** serves as a source or sink for data
- A port must be open before it can be read from or written to
- `(open-input-file filename)`
- `(close-input-port port)`
- `(open-output-file filename)`
- `(close-output-port port)`

### Read a Character

- `(read-char [input-port])` - port is optional
- `(peek-char [input-port])`
- `(eof-object? object)` - check if it reaches eof

Read and run the example `printfile4.scm` with

```bash
scheme --quiet < printfile4.scm
```

### Read a Line

- `(read-line [input-port])`
- `(eof-object? object)`

Read and run the example `printfile3.scm` with

```bash
scheme --quiet < printfile3.scm
```

### Read an Object

- `(read [input-port])` - Read external representation of next Scheme object (number, symbol, list) and return it
    - Note that a symbol, different from a string, will be stored in lowercase
- `(eof-object? object)`

Read and run the example `printfile2.scm` with

```bash
scheme --quiet < printfile2.scm
```

### Read a String

- `(read-string char-set [input-port])`
- `(eof-object? object)`
- `read-string` works only on Scheme version 9.2 (which we use), not the most recent version 11.2, which uses `read-delimited-string`

Read and run the example `printfile.scm` with

```bash
scheme --quiet < printfile.scm
```

### Output Ports

- `(write-char output-port char)`
- `(write-string output-port string)`
- `(write-substring output-port string start end)`
- `(write-line output-port string)`
- `(write output-port object)`

### String Ports

- `(open-input-string string [start [end]])`
- First, `open-input-string`, then write, then finally `get-output-string port` to get the combined string
- Similar to file input/output

Read and run the example `parsestring.scm` with

```bash
scheme --quiet < parsestring.scm
```

## Recursion

Recursion is used instead of iteration in functional languages.

Here is recursion to skip all the white spaces:

```scheme
(define (skip-whitespaces port)
    (let ((ch (peek-char port)))
        (if (and (not (eof-object? ch)) (char-whitespace? ch))
            (begin (read-char port)
                (skip-whitespaces port)
            )
        )
    )
)
```

## Sequencing

- `(begin expression expression ...)`
- The **expressions** are evaluated sequentially from left to right

```scheme
(begin
    (display "4 plus 1 equals ")
    (display (+ 4 1))
)
```
