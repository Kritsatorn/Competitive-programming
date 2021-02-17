#include<bits/stdc++.h>
using namespace std ;
struct Point {
  int Hight,Score ;
} point[1010];
int n ,k ,mem[1010];
main() {
  scanf("%d %d",&n,&k);
  for(int i=0 ; i<n;i++)
    scanf("%d %d",&point[i].Hight,&point[i].Score);
  int maxx = INT_MIN ;
  for(int i=0 ; i<n;i++) {
    bool Found = false ;
    int maxx_in = INT_MIN ;
    mem[i] = point[i].Score ;
    for(int j = i - 1 ;  j >= 0 ; j --) {
      if ( point[j].Hight - point[i].Hight <= k && point[j].Hight >= point[i].Hight)
        maxx_in = max( maxx_in , mem[j] ) ;
    }
    mem[i] = max( mem[i] , maxx_in + mem[i] ) ;
    maxx = max( maxx , mem[i]) ;
  }
  printf("%d",maxx);
}