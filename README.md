 # low-level-basic
A very low level basic programming language

## Design

This basic dialect is designed to be simple enough to implement in almost any language on any hardware, as its commands mirror assembly programming.

### Layout

LLB's memory and variables are accessed by number. The standard implementation requires the following:
- 10000 accessible float variables (7 decimal pt accuracy)
- 3 pointers:
  - ptr1: the first argument
  - ptr2: the second argument
  - ptr3: where the result is stored


## Commands

### Memory Commands

#### store [integer] [memory loc]
`store 100 10`
stores the value 100 into memory slot 10
#### storeascii [character] [memory loc]
`store a 10`
stores the ascii value of 'a' (97) into memory slot 10
#### storestr [string] [memory loc]
`store str 10`
stores the ascii value of 's' into slot 10; 't' into slot 11; 'r' into slot 12; and '\0' into slot 13

#### move [memory loc] [memory loc]
`move 10 20`
Copies memory slot 10 into memory slot 20

#### swap [memory loc] [memory loc]
`move 10 20`
Swaps memory slot 10 with memory slot 20

### Arithmetic

#### add [memory loc] [memory loc]
#### + [memory loc] [memory loc]
`add 10 20`
`+ 10 20`
Adds the memory stored in 10 with the memory stored in 20 and stores in 10


#### sub [memory loc] [memory loc]
#### - [memory loc] [memory loc]

`sub 10 20`
`- 10 20`
Subtratcs the memory stored in 10 by the memory stored in 20 and stores in 10

#### mul [memory loc] [memory loc]
#### * [memory loc] [memory loc]

`mul 10 20`
`* 10 20`
 Multiplies the memory stored in 10 by the memory stored in 20 and stores in 10

#### div [memory loc] [memory loc]
#### / [memory loc] [memory loc]

`div 10 20`
`/ 10 20`
Divides the memory stored in 10 by the memory stored in 20 and stores in 10

#### pow [memory loc] [memory loc]
#### ^ [memory loc] [memory loc]

`pow 10 20`
`^ 10 20`
Raises the memory stored in 10 to the memory stored in 20 and stores in 10

#### mod [memory loc] [memory loc]
#### % [memory loc] [memory loc]

`mod 10 20`
`% 10 20`
Divides the memory stored in 10 by the memory stored in 20 and stores the remainder in 10


### Logic

#### goto [memory loc]
`goto 10`
Moves execution pointer to line # 10

#### if [memory loc] [<,=,>,<=,>=,!=] [memory loc] goto [memory loc]
`if 10 >= 20 goto 15`
If memory 10 >= memory 20 move execution pointer to line # 15

#### strcomp [memory loc] [memory loc] goto [memory loc]
`if 10 20 goto 15`
If memory 10 = memory 20 move execution pointer to line # 15


#### end
`end`
Stops executing the program

### Input/Output

#### print [memory loc]
`print 10`
Prints the numerical value in memory 10

#### printascii [memory loc]
`printascii 10`
Prints the ascii value in memory 10

#### printstr [memory loc]
`printstr 10`
Prints the ascii values of the string starting in memory location 10

#### input [memory loc]
`input 10`
Inputs one number from the user and stores it in memory 10

#### inputascii [memory loc]
`input 10`
Inputs one character from the user and stores its ascii value in memory 10

#### inputstr [memory loc] [integer]
`inputstr 10 5`
Inputs one string up to '\n' from the user and stores its ascii values in memory 10 - memory 15 (Maxx length 5)
