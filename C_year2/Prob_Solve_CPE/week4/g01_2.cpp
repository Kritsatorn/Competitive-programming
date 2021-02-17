#include<stdio.h>
int n ,m  ;
char arr[130][130] ;
// direcction 0 = right || 1 = left
bool travel(int x,int y ,int direction) {
  printf("%d %d %d\n",x,y,direction);
  // end
  if ( arr[x][y] == '$' ) return true  ;
  if ( arr[x][y] == '@' ) return false ;
  // fall
  if ( arr[x][y] == '.' ) return travel(x+1,y,direction);
  //walk
  if ( arr[x][y] == '#') {
    if ( !direction ) {
      // chang direction
      //left
      if ( y == 0 ) return travel(x,y,1);
      else return travel(x,y-1,0) ;
    } else {
      //right
      if ( y == n-1) return travel(x,y,0);
      else return travel(x,y+1,1);
    }
  }

}
int group() {
  int count = 0 ,old_i ;
  int count_fall = 0;
  int count_walk = 0 ;
  for(int i=0 ; i < n ; i++) {
    if ( arr[0][i] == '.' ) {
      if ( count_fall == 0 ) {
         if ( travel(0,i,0) )
          count_fall = 2 * count_walk + 1;
      } else {
          if ( travel(0,old_i,0) )  count_fall += count_walk + 1 ;
          if ( travel(0,i,1) )  count_fall += count_walk + 1;
      }
      old_i = i ;
      count_walk = 0 ;
    }
    else count_walk ++;
    printf("for i = %d : %d %d\n",i,count_fall,count_walk);
  }
  if ( travel (0,old_i,1) ) count_fall += 2 * count_walk  + 1;
  return count_fall ;
}
main() {
  scanf("%d %d",&n,&m);
  for(int i=0;i<m;i++)
    scanf("%s",arr[i]);
  int ans ;
  ans = group();
  // cut
  int maxx = 0 ;
  for(int i=0 ; i < m ; i++)
    for(int j=0 ; j < n ; j++) {
      if( arr[i][j] != '#' ) continue ;
      arr[i][j] = '.';
      int count_cut=0 ;
      count_cut = group() ;
      maxx = maxx > count_cut ? maxx : count_cut ;
      arr[i][j] = '#';
    }
  // if( travel(0,5,0) )
  printf("%d %d",ans,maxx);
}