#include<stdio.h>
#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
  int n , m;
  while( cin >> n )  {
    if ( n == 0 ) break ;
    cin >> m ;
    char arr[110][110] = {0};
    for(int i=0 ; i < n ; i++ )
      scanf("%s",arr[i]);
    int ans = 0 ;
    // do
    for (int i=0 ; i<n ; i++)
      for (int j = 0 ; j <m ; j++) {
        if ( arr[i][j] != '1' ) continue ;

          for(int r=i ; r < n ; r ++)
          for(int f=j ; f < m ; f++ ) {
            bool ok = true ;

            for(int a=i ; a <=r ; a ++)
            for(int b=j ; b <=f ; b ++) {
              if ( arr[a][b] != '1' ) {
                ok = false ;
                a = r+1;
                b = f+1;
              }
            }

            if (ok) ans ++ ;
          }

      }
    
    cout << ans << endl ;

  }
  return 0;
}
