#include<stdio.h>
int n,m;
char arr[130][130] ;
const int  left  = 0 ;
const int  right = 1 ;
bool travel(int x, int y,int direction) {
  // printf("asd %d %d %d\n",x,y,direction);
  // end case
  if ( arr[x][y] == '$' ) return true ;
  if ( arr[x][y] == '@' ) return false ;

  // fall
  if ( arr[x][y] == '.' ) return travel(x+1,y,direction) ;

  // normal
  if ( direction == right ) {
    // change direction tight to left
    if ( y == n-1 ) return travel(x,y,left);
    else return travel(x,y+1,right);
  }
  else {
    if ( y == 0 ) return travel(x,y,right) ;
    else return travel(x,y-1,left);
  }
}
int group() {
  int prev_i = -1  ;
  int walk = 0    ;
  int count = 0   ;
  for(int i=0 ; i < n ;i++) {
    if ( arr[0][i] == '.' ) {
      if ( prev_i == -1 ) {
        if ( travel(0,i,right) ) count += walk*2 + 1  ;
      }
      else {
        if ( travel(0,prev_i,left) )  count += walk + 1 ;
        if ( travel(0,i,right) )      count += walk + 1 ;
      }
      prev_i = i ;
      walk = 0 ;
    } else walk ++ ;
    // printf(" now %d %d \n",count,walk);
  }
  if ( travel(0, prev_i , left) ) count += walk*2 +1 ;
  return count ;
}
int main(int argc, char const *argv[])
{
  scanf("%d %d",&n,&m);
  bool has_no_forAll = false ;
  for(int i=0 ; i < m ; i++) {
    scanf("%s",arr[i]);
  }

  int ans= 0 , ans_cut=0 ;
  ans = ans_cut = group() ;
  for(int i=0 ; i < m -1 ; i++)
  for(int j=0 ; j < n ; j++) {
    if  ( arr[i][j] != '#' ) continue ;
    if  ( i != 0 && i != m-2  && arr[i-1][j] != '.') continue ;
    // do
    arr[i][j] = '.' ;
    int tmp = 0 ;
    tmp = group() ;
    ans_cut = ans_cut > tmp ? ans_cut : tmp ;
    arr[i][j] = '#' ;
  }
  d :;
  printf("%d %d",ans,ans_cut);
  return 0;
}
