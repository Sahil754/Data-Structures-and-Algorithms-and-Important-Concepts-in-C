#include <stdio.h>

int main()
{
    int grades[2][5] = {{10,20,30,40,50},
                        {60,70,80,90,10}};
        float average;
        int i;
        int j;

        for (i = 0; i < 2; i++) {
            average = 0;
            
            for (j = 0; j < 5; j++) {
                average += grades[i][j];
            }

            average /= 5.0;
            printf("The average marks obtained in subject %d is: %.2f\n", i, average);
        }

    return 0;
}

