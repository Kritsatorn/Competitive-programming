#include<bits/stdc++.h>
int n ,k , a_taro[100010] , b_tora[100010] ;
int mem[100010] , check[100010] ;
using namespace std ;
int fight(int i,int count_a,int count_b) {
  if ( i > n     ) return 0 ;
  //|| 
  if ( check[i] ) return mem[i] ;
  check[i] = 1;
  int a = ( abs( (count_a + 1) - count_b) <= k) ?
  fight(i+1,count_a + 1,count_b) + a_taro[i] : INT_MAX ;
  int b = ( abs(count_a  - (count_b + 1)) <= k) ?
  fight(i+1,count_a,count_b + 1) + b_tora[i] : INT_MAX ;
  // printf("%d : %d %d\n",i,a,b);
  return mem[i] =  min(
     a
    ,b
  ) ;
}
main() {
  int c ;
  scanf("%d",&c);
  while( --c >= 0) {
  scanf("%d %d",&n,&k);

  mem[n] = {0} ;  check[n] = {0} ;
  for(int i=1 ; i<=n ;i ++)
    scanf("%d %d",&a_taro[i],&b_tora[i]);
  int x = fight(1,0,0) ;
  printf("%d\n",x);
  }

}