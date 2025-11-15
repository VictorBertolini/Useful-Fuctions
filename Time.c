#include <stdio.h>
#include <time.h>

/*
 * Algorithm destinated to check the time that a program or a part of spend to run
 * Will be write the algorithm in the comment part between the variables 't'
 * At the final it'll be printed in the form 'Claus' (a created measure)
*/

void
main() 
{
    //Creating the variable t
    clock_t t;

    //Start the program counting
    t = clock(); 

    /*
    ______________________________________
    |     Write your algorithm here      |
    ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾ 
    */
    
    //Stop the program counting
    t = clock() - t; 
    

    printf("The execution time is: %.2lf \n", (((double) t) / (CLOCKS_PER_SEC/1000)));
}
