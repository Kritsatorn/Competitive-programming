#include <bits/stdc++.h>
using namespace std;
main() {
    int n, k;
    while(cin >> n && n != 0){
        int arr[100] = {0};
        for(int i = 0; i < n; i++)
            scanf("%d", &k), arr[k]++;
        int count = 0;
        for(int i = 0; i < 100; i++){
            if(arr[i] > 0)
                for(int j = 1; j <= arr[i]; j++){
                    count++;
                    printf("%d", i);
                    if(count != n)
                        printf(" ");
                }
        }
        printf("\n");
    }
    return 0;
}