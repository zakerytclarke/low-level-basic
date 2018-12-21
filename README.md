 # low-level-basic
A very low level basic programming language

## Design

This basic dialect is designed to be simple enough to implement in almost any language on any hardware, as its commands mirror assembly programming.

### Layout

LLB's memory and variables are accessed by number. The standard implementation requires the following:
- 10000 accessible float variables (7 decimal pt accuracy)
- 3 pointers:
  - ptrx: pointer to memory (first argument)
  - ptry: pointer to memory (second argument)
  - ptrz: pointer to memory where result is stored


## Commands

### Memory Commands

#### ptrx [Integer]
#### ptry [Integer]
#### ptrz [Integer]
Sets pointer to a location in memory
`ptrx 10`
Pointer x now points at memory loc 10

#### putx [Integer]
#### puty [Integer]
#### putz [Integer]
Stores a value in the memory at the pointer
`
ptrx 10
putx 15
`
The memory location at 10 is now 15

#### movx [Integer]
#### movy [Integer]
#### movz [Integer]
Copies the value of memory at pointer x to another memory location
`
ptrx 0
putx 15
movx 1
`
Memory location 1 now is 15
#### swap
Swaps the memory values at pointer x and pointer y
`
ptrx 0
putx 15
ptry 1
puty 25
swap
`


### Logic

#### goto [Integer]
Moves execution pointer to line #
`goto 10`
Executes command at line 10 next
#### if= [Integer]
#### if> [Integer]
#### if< [Integer]
#### if<= [Integer]
#### if>= [Integer]
if value at ptrx [>,<,=,>=,<=,!=] value at ptr y then goes to line #

`
1. ptrx 0
2. putx 25
3. ptry 0
4. puty 15
5. if> 7
6. end
7. rem greater than
`


#### end
Terminates the program
`end`
#### rem
Ignored by compiler
`rem this is a comment`

### Arithmetic

#### add
#### sub
#### mul
#### div
#### pow
#### mod
Completes the given arithmetic operation on x,y and stores the result in z

`
ptrx 0
putx 116
ptry 1
puty 10
ptrz 2
mod
`
Memory 2 is now 6 (116%10)


### Input/Output

#### prt [Integer]
Prints numerical value at memory loc
#### prtc [Integer]
Prints character value at memory loc
#### prts [Integer]
Prints string starting at memory loc until '\0'
#### inp [Integer]
Reads in a numerical value from stdin to memory loc
#### inpc [Integer]
Reads in a character value from stdin to memory loc
#### inps [Integer]
Reads in character values from stdin to memory starting at ptrx
