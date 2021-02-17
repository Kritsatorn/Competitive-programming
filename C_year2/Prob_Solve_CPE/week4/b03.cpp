#include<stdio.h>
int n ,m ;
char arr[32][32] ;
int check[32][32] ;
bool ans ;
bool check_square(int x,int y) {
  if (arr[x][y]     != '.') return false ;
  if (arr[x+1][y]   != '.') return false ;
  if (arr[x+1][y+1] != '.') return false ;
  if (arr[x][y+1]   != '.') return false ;
  return true ;
}
void dfs (int x, int y ) {
  if  ( !check_square(x,y) ) return ;
  if  ( x + 1 == n-1) ans = true ;
  if  ( ans ) return ;
  if ( check[x][y] ) return ;
  check[x][y] = 1 ;
  if ( x -1 >= 0) dfs( x-1 , y ) ;
  if ( x +1 < n) dfs( x+1 , y ) ;
  if ( y -1 >= 0) dfs( x , y-1 ) ;
  if ( y -1 < m) dfs( x , y+1 ) ;
  check[x][y] = 0;
  return ;

}
int main(int argc, char const *argv[])
{
  scanf("%d %d",&n,&m);
  for(int i=0 ;i <n ;i++)
    scanf("%s",arr[i]);
  // start to m-1
  for(int j=0 ;j<m -1 ;j++) {
    if( check_square(0,j) )
      dfs(0,j) ;
  }
  if ( ans ) printf("yes");
  else printf("no");
  return 0;
}
