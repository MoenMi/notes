# 30 - Functional

## Scheme Topics Related to Assignment #7

- Popular list operations
- Variable number of arguments

## str-split

[GitHub Link](https://gist.github.com/matthewp/2324447)

```scheme
(define (str-split str ch)
    (let ((len (string-length str)))
        (letrec
            ((split
                (lambda (a b)
                    (cond
                        ((>= b len) (if (= a b) '() (cons (substring str a b) '())))
                            ((char=? ch (string-ref str b)) (if (= a b)
                                (split (+ 1 a) (+ 1 b))
                                    (cons (substring str a b) (split b b))))
                                (else (split a (+ 1 b)))))))
                                    (split 0 0))))
```

## my-str-split.scm

```scheme
(define (str-split-helper line str list)
    (cond
        ((string-null? line)
            (if (string-null? str)
                (reverse list)
                (reverse (const str line))))
        ((char=? (string-ref line 0) #\space)
            (if (string-null? str)
                (str-split-helper (string-tail line 1) str list)
                (str-split-helper (string-tail line 1 "" (cons str list))))
            (else
                (str-split-helper (string-tail line 1)
                    (string-append str (string-head line 1))
                    list))))
(define (str-split line) (str-split-helper line "" '())))
```

## Popular List Operations

- Selecting
    - `(first '("commission" "Floyd" "Jenkin" 300 3000 .08))`
    - `(sixth '("commission" "Floyd" "Jenkin" 300 3000 .08))`
- Filtering
    - `(filter odd? '(1 2 3 4 5)) => (1 3 5)`
    - `(filter (lambda (x) (< x value)) '(3 9 5 8 2 4 7))`
- Mapping
    - `(map cadr '((a b) (d e) (g h)))`
- Applying
    - `(apply min '(3 9 5 8 2 4 7))`

## Variable Number of Arguments

```scheme
(define (perform . args) (display (car args))
    (newline) (display (cdr args)))
```

```scheme
(define (perform action . args) (display action)
    (newline) (display args))
```
