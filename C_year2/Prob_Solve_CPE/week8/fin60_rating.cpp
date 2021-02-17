#include<bits/stdc++.h>
using namespace std ;
int arr[100010] ,n,m;
int mem[100010];
pair<int,int> maxx ;
main() {
  scanf("%d %d",&n,&m);
  for(int i=0 ; i <m ; i++) {
    scanf("%d",&arr[i]);
  }
  maxx = make_pair(INT_MAX,INT_MIN) ;
  for(int i=0 ; i<m;i++) {
    bool Found = false ;
    for(int j= i - 1 ; j >= i - 6 && j >= 0  ; j --) {
      if ( arr[j] == arr[i] ) {
        mem[i] = mem[j] + 1 ;
        //
        if ( ( mem[i] > maxx.second ) || ( mem[i] == maxx.second && arr[i] < maxx.first) )
          maxx.second = mem[i] , maxx.first = arr[i] ;
        Found = true ;
        break ;
      }
    }
    if ( !Found ) mem[i] = 1 ;
    // printf("number is %d : %d %d %d\n",arr[i],mem[i],maxx.first,maxx.second);
  }
  printf("%d %d",maxx.first,maxx.second);
}