/*The first seven rows of Pascal's triangle are shown below. Note that row i contains i elements. Therefore, to store the numbers from the first three rows, one would require 1 + 2 + 3 = 6 memory slots.

1

1 1

1 2 1

1 3 3 1

1 4 6 4 1

1 5 10 10 5 1

1 6 15 20 15 6 1

Complete the skeleton code given below to store the numbers from the first three rows of Pascal's triangle in a two-dimensional "array" using dynamic memory allocation. Note that you must allocate exactly six memory slots to store those six numbers. No extra memory should be allocated. At the end of your program, free all the memory blocks used in this program.*/


#include<stdio.h>
#include<stdlib.h>

int main()
{
    int nrows = 3;
    int ncols = 3;
    int i, j;
    
    // Allocate memory for nrows pointers
    char **pascal = (char **) malloc(nrows * sizeof(char *));
    
    // For each row, allocate memory for ncols elements
    pascal[0] = (char *) malloc(ncols * sizeof(char));
    pascal[1] = (char  *) malloc(ncols * sizeof(char));
    pascal[2] = (char *) malloc(ncols * sizeof(char));
    
    // 1st row
    pascal[0][0] = '1';
    
    // 2nd row
    pascal[1][0] = '1';
    pascal[1][1] = '1';
    
    // 3rd row
    pascal[2][0] = '1';
    pascal[2][1] = '2';
    pascal[2][2] = '1';
    
    for (i = 0; i < nrows; i++) {
        
        for (j = 0; j < ncols; j++) {
            printf("%c ", pascal[i][j]);
        }
        
        printf("\n");
    }
    
    // Free individual rows
    free(pascal[0]);
    free(pascal[1]);
    free(pascal[2]);
    
    // Free the top-level pointer
    free(pascal);
}
