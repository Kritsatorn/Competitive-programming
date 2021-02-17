#include<bits/stdc++.h>
using namespace std ;
int T , N , K , ANS , ARR[100010][2] ;
map< pair<int,int> , int > MAP ;
int fight(int TM , int A , int B){
  if ( TM >= N )
    if ( abs(A-B) <= K ) return 0 ;
    else return 999999999 ;
  pair<int , int > KEY = make_pair(A,B) ;
  auto PTR = MAP.find(KEY) ;
  if( PTR != MAP.end() ) return PTR -> second ;
  int VAL  = min(
    ARR[TM][0] + fight(TM+1 , A+1 , B) ,
    ARR[TM][1] + fight(TM+1 , A , B+1)
  ) ;
  MAP.insert( { KEY , VAL } ) ;
  return VAL ;
}
main() {
  scanf("%d",&T);
  for(int t=0 ; t<T ; t++){
    scanf("%d %d",&N,&K) ;
    MAP.clear();
    for(int n=0 ; n<N ; n++) scanf("%d %d",&ARR[n][0],&ARR[n][1]);
    ANS = fight(0,0,0) ;
    cout << ANS << endl ;
  }
}