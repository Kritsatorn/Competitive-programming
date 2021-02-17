#include<stdio.h>
int fuck[200010];
main() {
  int n, maxx = 0;
  scanf("%d",&n);
  while(n-- > 0) {
    int m , k ;
    scanf("%d %d",&k,&m);
    if ( k == 1) {maxx = maxx > m ? maxx : m ; fuck[m] = 1;}
    else if ( k == 2 ) {
      int count = 0 ;
      for(int i=m+1 ; i <=maxx ; i++)
        if ( fuck[i] )count ++ ;
      printf("%d\n",count) ;
    }
    // printf("maxx : %d \n",maxx);
  }
}