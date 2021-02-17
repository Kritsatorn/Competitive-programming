#include<bits/stdc++.h>
using namespace std ;
int N , K , arr[5010] ,mem[5010][5010];
int Food(int day , int food_left) {
  if ( day >= N) return 0 ;
  if ( mem[day][food_left] != 0 ) return mem[day][food_left] ;
  return  mem[day][food_left] = max (
    food_left - arr[day] >= 0 ? arr[day] + Food(day+1,food_left - arr[day])
    : Food(day+1,K)
    , Food(day+1,K)
  ) ;
}
main() {
  int SUM = 0 ;
  scanf("%d %d",&N,&K) ;
  for(int n=0 ; n <N ; n++) scanf("%d",&arr[n]) , SUM += arr[n] ;
  int ANS = Food(0,K) ;
  printf("%d\n",SUM - ANS);
  // cout << SUM - ANS << endl ;
}