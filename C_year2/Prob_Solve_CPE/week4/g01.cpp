#include<stdio.h>
int n ,m  ;
char arr[130][130] ;
int mem[130][130][2] ;
// direcction 0 = right || 1 = left
bool travel(int x,int y ,int direction) {
  // printf("%d %d %d\n",x,y,direction);
  // end
  if ( arr[x][y] == '$' ) return true  ;
  if ( arr[x][y] == '@' ) return false ;
  // fall
  if ( arr[x][y] == '.' ) return travel(x+1,y,direction);
  //walk
  if ( arr[x][y] == '#') {
    if ( direction ) {
      // chang direction
      //left
      if ( y == 0 ) return travel(x,y,0);
      else return travel(x,y-1,1) ;
    } else {
      //right
      if ( y == n-1) return travel(x,y,1);
      else return travel(x,y+1,0);
    }
  }

}

main() {
  scanf("%d %d",&n,&m);
  for(int i=0;i<m;i++)
    scanf("%s",arr[i]);
  int count = 0;
  for(int i=0;i<n;i++) {
    if ( travel(0,i,0) ) count++ ;
    if ( travel(0,i,1) ) count++ ;
  }
  // cut
  int maxx = 0 ;
  for(int i=0 ; i< m ; i++)
    for(int j=0 ; j< n ;j++) {
      if( arr[i][j] != '#' ) continue ;
      arr[i][j] = '.';
      int count_cut = 0 ;
      for(int l=0;l<n;l++) {
        if ( travel(0,l,0) ) count_cut++ ;
        if ( travel(0,l,1) ) count_cut++ ;
      }
      maxx = maxx > count_cut ? maxx : count_cut ;
      arr[i][j] = '#';
    }
  printf("%d %d",count,maxx);
}