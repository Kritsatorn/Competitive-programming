#include<bits/stdc++.h>
using namespace std;
int n ,arr[100010];
void fuck() {
  unordered_map<int,int> mp ;
  int dp[n] ;   memset(dp,0,sizeof(dp));
  int maxx = INT_MIN;

  int index = -1;
  for( int i = 0 ; i < n ; i++ ) {
    if( mp.find(arr[i] - 1) != mp.end() ) {
      int lastIndex = mp[arr[i] -1] - 1;
      dp[i] = 1 + dp[lastIndex] ;
    }
    else dp[i] = 1;
    mp[arr[i]] = i + 1;
    if ( maxx < dp[i] ) {
      maxx = dp[i] ;  index = i ;
    }
  }
  printf("%d\n",maxx);
  for (int i = arr[index] - maxx + 1; i <= arr[index]; i++)
      printf("%d ", i) ;
}
main() {
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  scanf("%d",&arr[i]);
  fuck();
  // int lis[n+1];
  // lis[0] = 1 ;
  // for(int i=1 ; i<n;i++){
  //   lis[i] = 1;
  //   for(int j=0 ; j <i ; j++ ) {
  //     if ( arr[i] > arr[j] && lis[i] < lis[j] +1) {
  //       lis[i] = lis[j] +1;
  //     }
  //   }
  // }
  // int  k = *max_element(lis, lis+n) ;
  // printf("%d",k);
}