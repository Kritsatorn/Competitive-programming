#include<stdio.h>
char arr[32][32] ;
int check[32][32] ,n,m ;
int  count ;
bool forrest , ore ;
int count_forrest ,count_ore ;
void dfs(int x,int y) {

  if( arr[x][y] == '#') return  ;
  if ( check[x][y] ) return ;
  check[x][y] = 1;
  count ++ ;
  if( arr[x][y] == '*') forrest = true ;
  if( arr[x][y] == '$') ore = true ;

  if( x - 1 >= 0 ) dfs(x-1  ,y    ) ;
  if( y - 1 >= 0 ) dfs(x    ,y-1  ) ;
  if( x + 1 <  n ) dfs(x+1  ,y    ) ;
  if( y + 1 <  m ) dfs(x    ,y+1  ) ;

  return ;
}
main() {
  scanf("%d %d",&n,&m);
  for(int i=0 ;i <n ;i++)
    scanf("%s",arr[i]);

  for(int i=0 ;i <n ;i++)
    for(int j=0 ;j<m ;j++) {
      if ( !check[i][j] ) {
      if( arr[i][j] == '#') {
        check[i][j] = 1;
        continue ;
      }

      forrest = false ;
      ore = false ;
      count = 0 ;
      dfs(i,j) ;
      // printf("zdszd %d %d %d\n",forrest,ore,count);
      if ( forrest && ore ) count_forrest += count ;
      else if ( forrest || ore ) count_ore += count ;
      }
    }
  printf("%d %d",count_forrest,count_ore);
}