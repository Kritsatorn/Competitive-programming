#include<bits/stdc++.h>
using namespace std ;
int T , N , K , ANS , ARR[100010][2] , MAX_ARR , MEM[1000][1000];
int fight(int TM,int A,int B){
  if ( TM >= N )
    if ( abs(A-B) <= K ) return 0 ;
    else return 999999999 ;
  if( MEM[A][B] != -1) return MEM[A][B] ;
  return MEM[A][B] = min(
    ARR[TM][0] + fight(TM+1 , A+1 , B) ,
    ARR[TM][1] + fight(TM+1 , A , B+1)
  ) ;
}
main() {
  scanf("%d",&T);
  for(int t=0 ; t<T ; t++){
    scanf("%d %d",&N,&K) ;
    memset(&MEM[0][0],-1,sizeof(MEM));
    // for(int i=0 ; i<1000; i++) for(int j=0; j<1000 ; j++ ) MEM[i][j] = -1 ;
    for(int n=0 ; n<N ; n++) scanf("%d %d",&ARR[n][0],&ARR[n][1]);
    MAX_ARR = *max_element(&ARR[0][0] , &ARR[0][0] + N*2 );
    ANS = fight(0,0,0) ;
    cout << ANS << endl ;
    // cout << "MAX " << INT_MAX -  MAX_ARR << endl ;
  }
}