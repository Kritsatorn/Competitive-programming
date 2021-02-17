#include<bits/stdc++.h>
using namespace std ;
int N , K , arr[5010] ,mem[5010][5010];
main() {
  int SUM = 0 ;
  scanf("%d %d",&N,&K) ;
  for(int n=0 ; n <N ; n++) scanf("%d",&arr[n]) , SUM += arr[n] ;
  for(int i=0; i<N;i++)for(int j=0 ; j<K;j++);
  printf("%d\n",0);
  // cout << SUM - ANS << endl ;
}