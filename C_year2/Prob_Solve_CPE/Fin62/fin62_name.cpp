#include<bits/stdc++.h>
using namespace std ;
char T[100010] , S[110] ;
int  NS , NT ,mem[100010][110] ;
int Name(int t, int s, int times) {
  if ( t > NT - 1) return 0 ;
  return  (
    T[t] == S[s] ?
      s + 1 >= NS - 1 ?
      1 + Name(t+1,0,times+1) : Name(t+1,s+1,times)
      : Name(t+1,s,times)
  ) ;
}
main() {
  scanf("%s",S)  ;
  scanf("%s",T)  ;
  NS = strlen(S) ;
  NT = strlen(T) ;
  int ANS = Name(0,0,0);
  cout << ANS << endl ;
}