#include <stdio.h>

int input[] = {17, 4, 6, 8, 11, 5, 13, 19, 0, 24};
int bitsum[10];
int bitvector[10];
int output[10];

int main() {
    int i;
    int count = 0;
    int index = 0;
    
    for(i=0; i < 10; i++)
        if(input[i] >= 6) {
            count++;
            bitvector[i] = 1;
        }
        else
            bitvector[i] = 0;
    
    bitsum[0] = bitvector[0];
    for(i=1; i < 10; i++)
        bitsum[i] = bitsum[i-1] + bitvector[i];

    for(i=0; i < 10; i++)
        if(bitvector[i]==1)
            output[bitsum[i]-1] = input[i];

    for(i=0; i<10; i++)
        printf("%d ", bitsum[i]);
    printf("\n");

    for(i=0; i<count; i++)
        printf("%d ", output[i]);
    printf("\n");

   return 0;
}