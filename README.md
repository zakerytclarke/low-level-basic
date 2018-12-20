# low-level-basic
A very low level basic programming language

## Design

This basic dialect is designed to be simple enough to implement in almost any language on any hardware, as its commands mirror assembly programming.

### Layout

LLB's memory and variables are accessed by number. The standard implementation requires the following:
- 10000 accesible float variables (7 decimal pt accuracy)

## Commands

### Memory Commands

#### load [integer] [variable #]
`load 100 10`
Loads the value 100 into memory slot 10
#### loadascii [character] [variable #]
`load a 10`
Loads the ascii value of 'a' (97) into memory slot 10
#### loadstr [string] [variable #]
`load str 10`
Loads the ascii value of 's' into slot 10; 't' into slot 11; 'r' into slot 12; and '\0' into slot 13

#### move [variable #] [variable #]
`move 10 20`
Copies memory slot 10 into memory slot 20

#### swap [variable #] [variable #]
`move 10 20`
Swaps memory slot 10 with memory slot 20

### Arithmetic

#### add [variable #] [variable #]
#### + [variable #] [variable #]
`add 10 20`
`+ 10 20`
Adds the memory stored in 10 with the memory stored in 20 and stores in 10


#### sub [variable #] [variable #]
#### - [variable #] [variable #]

`sub 10 20`
`- 10 20`
Subtratcs the memory stored in 10 by the memory stored in 20 and stores in 10

#### mul [variable #] [variable #]
#### * [variable #] [variable #]

`mul 10 20`
`* 10 20`
 Multiplies the memory stored in 10 by the memory stored in 20 and stores in 10

#### div [variable #] [variable #]
#### / [variable #] [variable #]

`div 10 20`
`/ 10 20`
Divides the memory stored in 10 by the memory stored in 20 and stores in 10

#### pow [variable #] [variable #]
#### ^ [variable #] [variable #]

`pow 10 20`
`^ 10 20`
Raises the memory stored in 10 to the memory stored in 20 and stores in 10

#### mod [variable #] [variable #]
#### % [variable #] [variable #]

`mod 10 20`
`% 10 20`
Divides the memory stored in 10 by the memory stored in 20 and stores the remainder in 10


### Logic

#### goto [variable #]
`goto 10`
Moves execution pointer to line # 10

#### if [variable #] [<,=,>,<=,>=,!=] [variable #] goto [variable #]
`if 10 >= 20 goto 15`
If memory 10 >= memory 20 move execution pointer to line # 15

#### end
`end`
Stops executing the program

### Input/Output

#### print [variable #]
`print 10`
Prints the numerical value in memory 10

#### printascii [variable #]
`printascii 10`
Prints the ascii value in memory 10

#### printstr [variable #]
`printstr 10`
Prints the ascii values of the string starting in memory location 10

#### input [variable #]
`input 10`
Inputs one number from the user and stores it in memory 10

#### inputascii [variable #]
`input 10`
Inputs one character from the user and stores its ascii value in memory 10

#### inputstr [variable #] [integer]
`inputstr 10 5`
Inputs one string up to '\n' from the user and stores its ascii values in memory 10 - memory 15 (Maxx length 5)


