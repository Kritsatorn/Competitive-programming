#include<bits/stdc++.h>
using namespace std ;
int n , m ,arr[1010];
main() {
  scanf("%d %d",&n,&m) ;
  for(int i=2 ; i<=n ; i++) scanf("%d",&arr[i]) ;
  int a  ,b , k;
  queue<int> ans ;
  for(int i= 0 ; i <m ; i ++) {
    bool Found = false ;
    scanf("%d %d",&a,&b) ;
    k = a ;
    while(arr[k] != 0 && !Found) {
      if ( arr[k] == b) ans.push(b), Found = true ;
      else k = arr[k] ;
    }
    k = b ;
    while(arr[k] != 0 && !Found) {
      if ( arr[k] == a) ans.push(a), Found = true ;
      else k = arr[k] ;
    }
    if ( ! Found ) ans.push(-1) ;
  }
  while( ! ans.empty() )printf("%d\n",ans.front()) , ans.pop() ;
}