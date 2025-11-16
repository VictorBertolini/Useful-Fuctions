#include <stdio.h>
#include <time.h>

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
