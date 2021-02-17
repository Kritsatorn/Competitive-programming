#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int s[1010];
int t[1010];
int w[1010];
int dp[1010];
int ct[1010];
int backtrack[1010];

void printBacktrack(int i){
    if(i == backtrack[i]) printf("%d ", i+1);
    else{
        printBacktrack(backtrack[i]);
        printf("%d ", i+1);
    }

}

int main(){
    int sol = 0;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d %d %d", &s[i], &t[i], &w[i]);
        backtrack[i] = i;
    }

    for(int i=0; i<N; i++){
        int MAX = 0, ctMAX = 0;
        for(int j=0; j<i; j++){
            if(t[j] <= s[i] or s[j] >= t[i]){
                if(MAX < dp[j]){
                    ctMAX = ct[j];
                    MAX = dp[j];
                    backtrack[i] = j;
                }
            }
        }
        dp[i] = MAX + w[i];
        ct[i] = ctMAX + 1;
        if(dp[sol] < dp[i]) sol = i;
    }
    printf("%d\n%d\n", dp[sol], ct[sol]);
    printBacktrack(sol);
}