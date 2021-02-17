#include <stdio.h>

int n = 7;
int pascal[8][8];

int main() {
    pascal[1][1] = 1;
    
    // fill in Pascal's triangle
    for (int i = 2; i <= n; i++)
        for (int j = 1; j < i + 2 - 1; j++)
            pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];

    // print results
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i + 2 - 1; j++) {
            printf("%d", pascal[i][j]);
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}