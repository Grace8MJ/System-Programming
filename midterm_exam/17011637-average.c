#include <stdio.h>
  
int main(void)
{
        int system, algorithm, network;
        float average;

        printf("Input the system programming, algortihm, and network score:");
        scanf("%d%d%d", &system, &algorithm, &network);

        average = (float)(system + algorithm + network) / 3;

        printf("The average of the three subjects is %.2f.\n", average);

        return 0;

}

