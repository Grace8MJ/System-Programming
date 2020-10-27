#include <stdio.h>
  
int main(void)
{
        float system, algorithm, network;	// int --> float
        float average;						// int --> float

        printf("Input the system programming, algortihm, and network score:");
        scanf("%f%f%f", &system, &algorithm, &network);	// %d -> %f

        average = (system + algorithm + network) / 3;	// system+algorithm+network/3 --> (system+algorithm+network)/3

        printf("The average of the three subjects is %.2f.\n", average);	// %d --> %.2f

        return 0;

}

