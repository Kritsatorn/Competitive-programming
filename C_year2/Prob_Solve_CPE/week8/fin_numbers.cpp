#include<bits/stdc++.h>
using namespace std;
pair<int,int> stair_cases[100010] ;
int n ,mem[100010] ;
main() {
  scanf("%d",&n) ;
  for(int i=1; i <=n ; i++)
    scanf("%d",&stair_cases[i].first) ;
  for(int i=1; i <=n ; i++)
    scanf("%d",&stair_cases[i].second);
  mem[0] = 0 ;
  stair_cases[0] = make_pair(0,1) ;
  for(int i=1 ; i <=n ; i++) {
    int maxx = INT_MIN ;
    for(int j = i -1 ; j > i - 5 && j >= 0 ; j --) {
      maxx = max ( maxx, mem[j] ) ;
      if ( stair_cases[j].second == 1 ) break;
    }
    mem[i] = maxx + stair_cases[i].first ;
    // printf("%d %d : %d\n",stair_cases[i].first , stair_cases[i].second,mem[i]);
  }
  int maxx_ans = INT_MIN ;
  for(int i = n ; i > n - 4 ; i --) {
    maxx_ans = max ( maxx_ans , mem[i]);
    if ( stair_cases[i].second == 1 ) break;
  }
  printf("%d",maxx_ans);
}