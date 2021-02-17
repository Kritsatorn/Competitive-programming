#include<bits/stdc++.h>
using namespace std ;
int boss[100010] ;
int find_head(int k) {
  while( boss[k] != 0)
    k = boss[k] ;
    return k ;
}
main() {
  int n, m ;
  scanf("%d %d",&n,&m);
  // for(int i=1 ; i <=n ; i ++)
  //   boss[i] = i ;

  int num1 ,num2 ,x ,y ,xrank ,yrank;
  char c ;
  for(int i=0 ; i < m ; i++) {
    scanf(" %c %d %d",&c,&num1,&num2);
    // printf("%c %d %d\n",c,num1,num2);
    // x = find_head(num1) ;
    // y = find_head(num2) ;
    x = num1 ;  xrank = 0 ;
    y = num2 ;  yrank = 0 ;

    while( boss[x] != 0)
      x = boss[x] , xrank++ ;
    while( boss[y] != 0)
      y = boss[y] , yrank++ ;

    switch(c) {
      case 'c' :
        if ( x != y)
          if ( xrank >= yrank) boss[y] = x ;
          else boss[x] = y ;
      break ;
      case 'q' :
        if ( x!= y )printf("no\n") ;
        else printf("yes\n");
      break ;
    }
  }
}