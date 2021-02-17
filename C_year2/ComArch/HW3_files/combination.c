#include <stdio.h>

int combination(int n, int k)
{
    printf("%d %d\n",n,k);
    if (k == 0 || n == k)
        return 1;
    else if (n > k)
        return combination(n-1, k) + combination(n-1, k-1);
    return 0;
}

int main()
{
    int x;
    x = combination(5, 3);
    printf("%d\n", x);

    return 0;
}
