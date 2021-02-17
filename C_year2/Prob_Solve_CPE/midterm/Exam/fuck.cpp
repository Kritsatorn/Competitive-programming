#include<bits/stdc++.h>
using namespace std ;
int n,m ;
int arr[200020] , mem[200020] ;
int bs(int x) {
  int l = 0 ; int r = n-1 ;
  
}
int fuck ;

main() {
  scanf("%d %d",&n,&m);
  int minn = INT_MAX ; int maxx = 0 ;
  for(int i=0 ; i<n ; i++) {
    scanf("%d",&arr[i]);
    minn = min(minn,arr[i]);
    mem[i] = minn ;
  }
  // int k = 120 ;
  // printf("%d \n",binarySearch(mem,0,n-1,k));
  // while(fuck+1 < n ) {
  //           if ( k == mem[fuck+1])fuck++;
  //           else break;
  //       }
  // printf("%d",fuck +1);
  int l , k ;
  for(int i=0 ; i<m;i++) {
    scanf("%d %d",&l,&k);
    switch (l)
    {
    case 1:
      printf("%d\n",mem[k-1]);
      break;
    case 2:
      binarySearch(mem,0,n-1,k);
      if ( k > mem[0] ) printf("0\n");
      // else if ( k <= minn) printf("%d \n",n);
      else {
        while(fuck +1 < n) {
          if ( mem[fuck+1] == k) fuck ++;
          else break ;
        }
        if ( fuck +1 < n ) {
          if ( mem[fuck+1] <= k) fuck ++ ;
        }
        if ( fuck == n -1 && k <= mem[fuck]) fuck++;
        printf("%d\n",fuck);
      }
      break;
    }
  }
}