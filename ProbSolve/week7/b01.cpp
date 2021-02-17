#include<bits/stdc++.h>
using namespace std;
int mem[100010] ,n;
int inp[100010];
main() {
  scanf("%d",&n);
  for(int i=0 ; i < n ; i++)
    scanf("%d",&inp[i]);
    mem[0] = 0 ;
    mem[1] = 0 ;
    mem[2] = inp[2];
    for(int i=3 ; i < n ; i++) {
      if ( mem[i-1] > mem[i-3] + inp[i]) mem[i] = mem[i-1];
      else mem[i] = mem[i-3] + inp[i] ;
    }
  // for(int i=2; i<n; i++) {
  //   if ( mem[i-2] + inp[i] > mem[i-1] ) {
  //     mem[i] = mem[i-2] + inp[i] ;
  //     if ( i == n - 1) continue;
  //     mem[i+1] = mem[i] ;
  //     i++;
  //   }
  //   else
  //     mem[i] = mem[i-1];
    // printf("%d %d %d\n",mem[i],mem[i-1],mem[i-2]);
  // }
  printf("%d",mem[n-1]);
}