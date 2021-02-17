#include<bits/stdc++.h>
using namespace std ;
int n ,price[100010],dis[100010];
int mem[100010] ,check[100010];
int Recycle(int i , bool fuck) {
  int minn = INT_MAX ;
  if ( i > n ) return 0 ;
  if ( check[i] ) return mem[i];
  check[i] = 1 ;

  // activate
  for(int j = i + 1 ; j <= i + dis[i] && j <= n ; j ++) {
      minn = min ( Recycle(j , true) , minn) + price[i] ;
      printf("in %d loop %d \n",i,minn);
  }
  //
  if( fuck )
  for(int j = i + 1 ; j <= i + 5 && j <= n ; j ++) {
    if ( dis[j] >= j - i )
      minn = min ( Recycle(j , false) , minn)  ;
  }
  if ( minn = INT_MAX) minn = 0 ;
  printf("%d %d\n",i,minn);
  return mem[i] = minn ;
}
main() {
  scanf("%d",&n);
  for(int i=1 ; i<=n ;i++)
    scanf("%d %d",&price[i],&dis[i]);
  int x = Recycle(1,false) ;
  printf("%d",x);
}