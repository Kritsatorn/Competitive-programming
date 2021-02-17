#include<iostream>
using namespace std ;
int n ,m ,s ;
int x , y , direction ;
char arr[110][110] ;
bool after_move(int a,int b) {

  if ( arr[a][b] == '#' ) return false ;
  x = a  ;  y = b;
  if ( arr[a][b] == '.' ) return false ;
  if ( arr[a][b] == '*' )
    arr[a][b] = '.' ;
  return true ;
}
bool move () {
  switch ( direction ) {
    case 0 :
      if ( x - 1 < 0 ) return false ;
      if ( after_move(x-1,y) ) return true ;
      else return false ;
      break;
    case 1 :
      if ( y + 1 >= m ) return false ;
      if ( after_move(x,y+1) ) return true ;
      else return false ;
      break;
    case 2 :
      if ( x + 1 >= n ) return false ;
      if ( after_move(x+1,y) ) return true ;
      else return false ;
      break;
    case 3 :
      if ( y - 1 < 0 ) return false ;
      if ( after_move(x,y-1) ) return true ;
      else return false ;
      break;
  }
}
int main() {

  while( cin >> n >> m >> s) {
    if ( n == 0 || m == 0 || s == 0) break;
    arr[110][110] = {0} ;
    int ans = 0 ;
    // initial
    for(int i=0 ; i <n ; i++)
    cin >> arr[i] ;
    // for(int i=0 ; i <n ; i++)
    // cout << arr[i] << endl ;

    for(int i=0 ; i <n ; i++)
      for(int j =0 ; j < m ; j++) {
        // cin >> arr[i][j] ;
        if ( arr[i][j] == '.' || arr[i][j] == '#'|| arr[i][j] == '*') continue;

        x = i ;   y = j ;
        switch (arr[i][j]) {
          case 'N':
            direction = 0 ;
            break;
          case 'L':
            direction = 1 ;
            break;
          case 'S':
            direction = 2 ;
            break;
          case 'O':
            direction = 3 ;
            break;
        }
        arr[i][j] = '.';
      }
    // do
    char d[100000] ;
    cin >> d ;
    // cout << d << endl ;
    for(int i=0 ; i < s ; i++) {
      char c ;
      c = d[i] ;
      switch (c)
      {
        // turn left
      case 'E':
        direction = ( direction + 4 - 1 ) % 4 ;
        break;
        // turn right
      case 'D':
        direction = ( direction + 1 ) % 4 ;
        break;
      case 'F':
        if ( move() ) ans ++ ;
        break;
      }
      // cout << x << "  " << y << endl ;
      // cout << "di :" << direction << " " << arr[x][y] << endl ;
    }

    cout << ans << endl;
  }
  return 0;
}