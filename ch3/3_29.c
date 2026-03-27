//page 232 - stopped 

//page 238 -  CH3.7 

/* Example of for loop containing a 

continue statement */

/* Sum even numbers between 0 and 9 */
void ex() 
{long sum = 0;
long i;
for (i = 0; i < 10; i++) {
    if (i & 1)
        continue;
    sum += i;
}   
}

// A. What would we get if we naively applied our rule for translating the for loop
// into a while loop? What would be wrong with this code?

// it will not increment i if you continue 

// B. How could you replace the continue statement with a goto statement to
// ensure that the while loop correctly duplicates the behavior of the for loop?

// skip over the logic code to where you increment i right before the goto Loop 