# fastest_fizzbuzz
An attempt to implement fastest fizzbuzz.

See - https://codegolf.stackexchange.com/questions/215216/high-throughput-fizz-buzz/

## Testing the implementation

Pipe the out through pv (Pipe Viewer) to /dev/null

`fizzbuzz | pv > /dev/null`

## Solving FizzBuzz

Fizzbuzz is a very basic programming problem, legend has it that it
is used to weed out people who can't program
but are confident enough to apply
for programming jobs.

Solving Fizzbuzz requires the following know how

1. Loops
2. Conditional branches
3. Writing data to STDOUT

A sample implementation in C is given in 'fizz.c'.

### A Branchless Implementation of FizzBuzz

- A version of FizzBuzz without branching is given in `fizz_branchless.c`

- This branchless version averages around - 470 Mib/s

- Run `make fizz_branchless` to see it in action.


## How fast can you share data between two separate OS processes

### Baseline

`yes` - A unix utility which outputs the character y and a newline on the STDOUT.


`yes | pv > /dev/null` clocks an impressive 8.8 Gib/s

Considering that `yes`'s only job is to emit `y\n`, 8.8 Gib/s is an
upper bound on my laptop.


### Implementing Fastest FizzBuzz

We will first implement a fast version of `yes` program 
and hope to match the thoughput of standard `yes`.






