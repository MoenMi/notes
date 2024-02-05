# 11 - Loops

## Iterative Statements

The repeated execution of a statement or compound statement is accomplished either by iteration or recursion.

General design issues for iteration control statements:
- How is iteration controlled?
- Where is the control mechanism in the loop?

### Counter-Controlled Loops

A counting iterative statement has a loop variable and a means of specifying the *initial*, *terminal*, and *stepsize* variables.

Design issues:
- What are the type and scope of the loop variable?
- Should it be legal for the loop variable or loop parameters to be changed in the loop body, and if so, does the change affect loop control?
- Should the loop parameters be evaluated only once, or once for every iteration?
- What is the value of the loop variable after loop termination?

In C-based languages:
```C
for ([expr_1]; [expr_2]; [expr_3]) statement
```

- The expressions can be whole statements, or even statement sequences, with the statements separated by commas
    - The value of a multiple-statement expression is the value of the last statement in the expression
    - If the second expression is absent, it is an infinite loop
- Design choices
    - There is no explicit loop variable
    - Everything can be changed in the loop
    - The first expression is evaluated once, but the other two are evaluated with each iteration
    - It is legal to branch into the body of a for loop in C

C++ differs from C in two ways:
- The control expression can also be Boolean
- The initial expression can include variable definitions (scope is from the definition to the end of the loop body)

Java and C# differ from C++ in that the control expression must be Boolean.

In Python:
```Python
for loop_variable in object:
    # loop body
[else:
    # else clause
]
```
- The `object` in Python is often a range, which is either a list or a call to the `range` function
- The loop variable takes on the values specified in the given range, one for each iteration
- At loop termination, the loop variable has the last value that was assigned to it
- The optional `else` clause is executed if the loop terminates normally (no `break`)

In F#:
```F#
let rec forLoop loopBody reps =
    if reps <= 0 then ()
    else
        loopBody()
        forLoop loopBody, (reps - 1)
```
- Because counters require variables, and functional languages do not have variables, counter-controlled loops must be simulated with recursive functions
- The example above defines the recursive function `forLoop` with the parameters `loopBody` (a function that defines the loop's body) and `reps` (the number of repitions)
- `()` means do nothing and returns nothing

### Logically-Controlled Loops

In **logically-controlled loops**, repetition control is based on a Boolean expression.

Design issues:
- Pretest or posttest?
- Are both logically-controlled loops and counter-controlled loops needed?

C and C++ both have pretest and posttest forms, in which the control expression can be arithmetic:
```C
while (control_expr)
    loop body;

do
    loop body
while (control_expr)
```
- In both C and C++, it is legal to branch into the body of a logically-controlled loop

Java is like C and C++, except the control expression must be Boolean (and the body can only entered at the beginning, since Java has no `goto`).

In F#:
```F#
let rec whileLoop test body =
    if test() then
        body()
        whileLoop test body
    else ()
```
- As with counter-controlled loops, logically-controlled loops can be simulated with recursive functions
- This defines the recursive function `whileLoop` with parameters `test` and `body`

### User-Located Loop Control Mechanisms

Sometimes it is convenient for the programmers to decide a location for loop control (other than the top or bottom of the loop).

This is a simple design issue for single loops (e.g. `break`), but nested loops must consider the following design issues:
- Should the conditional break be part of the exit?
- Should control be transferable out of more than one loop?

C, C++, Python, Ruby, and C# have unconditional unlabeled exits (`break`).

Java and Perl have unconditional labeled exits (`break` in Java, `last` in Perl).

C, C++, and Python have an unlabeled control statement `continue` that skips the remainder of the current iteration, but does not exit the loop.

Java and Perl have labeled versions of `continue`.

### Iteration Based on Data Structures

- The number of elements in a data structure controls loop iteration
- Control mechanism is a call to an *iterator* function that returns the next element in some chosen order, if there is one; else loop is terminated.
- C's `for` can be used to build a user-defined iterator:

```C
for (p=root; p==NULL; traverse(p)) {
    ...
}
```

In PHP:
- `current` points at one element of the array
- `next` moves `current` to the next element
- `reset` moves `current` to the first element

Java 5.0 uses `for`, although it is called foreach.
- This works for arrays and classes that implement the `Iterable` interface (e.g. `ArrayList`):
```Java
for (String myElement : myList) { ... }
```

C# and F# (and the other .NET languages) have generic library classes, like Java 5.0 (for arrays, lists, stacks, and queues). These can be iterated over with the `foreach` statement. User-defined collections can also implement the `IEnumerator` interface and also use `foreach`.

```C#
List<String> names = new List<String>();
names.add("Bob");
names.add("Carol");
names.add("Ted");
foreach (Strings name in names)
    Console.WriteLine("Name: {0}", name);
```

Ruby *blocks* are sequences of code, delimited by either braces or `do` and `end`
- Blocks can be used with methods to create iterators
- Predefined iterator methods (`times`, `each`, `upto`):
    ```Ruby
    3.times {puts "Hey!"}
    list.each {|value| puts value}
    ```
    - `list` is an array, `value` is a block parameter
    ```Ruby
    1.upto(5) {|x| print x, " "}
    ```

## Guarded Commands

Guarded commands were designed by Djikstra. Their purpose is to support a new programming methodology that supports verification (correctness) during the development. The basic idea is that if the order of evaluation is not important, the program should not specify one.

General form:
```
if <Boolean expr> -> <statement>
[] <Boolean expr> -> <statement>
...
[] <Boolean expr> -> <statement>
fi
```
- Semantics: when construct is reached:
    - Evaluate all Boolean expressions
    - If more than one are true, choose one non-deterministically
    - If none are true, it is a runtime error

Selection guarded form:
```
if x>=y -> max := x
[] y>=x -> max := y
fi
```

Loop guarded command:
```
do <Boolean> -> <statement>
[] <Boolean> -> <statement>
...
[] <Boolean> -> <statement>
od
```
- Semantics: for each iteration,
    - Evaluate all Boolean expressions
    - If more than one are true, choose one non-deterministically; then start loop again
    - If none are true, exit loop

### Example

Given four integer variables `q1`, `q2`, `q3`, and `q4`, rearrange the values of the four so that `q1` $\leq$ `q2` $\leq$ `q3` $\leq$ `q4`:

```
do q1 > q2 -> temp := q1; q1 := q2; q2 := temp;
[] q2 > q3 -> temp := q2; q2 := q3; q3 := temp;
[] q3 > q4 -> temp := q3; q3 := q4; q4 := temp;
od
```
