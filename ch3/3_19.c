/*

Running on an older processor model, our code required around 16 cycles when
the branching.pattern was highly predictable, and around 31 cycles when.the
pattern was random.

A. What is the approximate miss penalty?
T_mp  =  2 ( T_ran - T_OK) 

2 ( 31 - 16 ) = 30 cycles 

B. How many cycles would the function require when the branch is mispre-
dicted?,

16 + 30 = 46

*/