#include<bits/stdc++.h>
using namespace std ;
int n , mem[100010][3] ;
bool check[100010][3] ;
int price[3][100010] ;
int opt(int i,int shop) {
  if ( i > n ) return 0 ;
  if ( check[i][shop] ) return mem[i][shop] ;
  check[i][shop] = 1 ;
  if ( shop == 2)
    return mem[i][shop] = max (
    max (opt( i + 1 , 2) , opt( i + 1,0))
    , opt(i+1,1)
  );
  int other = shop == 0 ? 1 : 0 ;
  return mem[i][shop] = price[shop][i] +  max ( opt(i+1 , 2) , opt(i+1,other) ) ;
}
main() {
  scanf("%d",&n) ;
  for(int i=1 ; i <= n ; i++)
    scanf("%d %d",&price[0][i] , &price[1][i]);
  int a = opt(1,0);
  int b = opt(1,1);
  int c = opt(1,2);
  printf("%d", max( max(a,b) , c ) );
}