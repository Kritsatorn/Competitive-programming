#include<bits/stdc++.h>
using namespace std ;
int n ,m ;
int mem[1010], num[1010],ans[100010] ;
set<int> fuck; // to hash
main() {
  scanf("%d %d",&n,&m);
  for(int i=1 ;i <=n;i++) {
    scanf("%d",&num[i]);
    mem[i] = num[i];
    mem[i] += mem[i-1];
  }
  for(int i=0 ; i <m ;i ++) {
     scanf("%d",&ans[i]);
  }
  //=---
  int k ;
  for(int i = 1 ;i <=n ;i++)
   for(int j = 1 ; j<=i ;j++) {
     k = mem[i] - mem[j-1] ;
     fuck.insert(k);
   }
   // ===
   for(int i=0 ; i <m ;i ++){
     if( fuck.find(ans[i]) != fuck.end() )printf("Y");
     else printf("N");
   }
}