#include<bits/stdc++.h>
using namespace std;
struct SP_Q{
  int SP;
  pair<int,int> POINT , PRE ;
  bool operator<(const SP_Q& a) const{
    return SP > a.SP;
  }
} ;
priority_queue<SP_Q> q;
int h,w ;
char cliff[40][40] ;
bool check[40][40] ;
int ANS_SP[40][40] ;
pair<int,int> PRE_P[40][40] ;
main() {

  scanf("%d %d",&h,&w);
  for(int i=0;i<h ; i++) scanf("%s",cliff[i]);
  for(int i=0 ; i < h ; i++) for(int j=0;j<w ; j++) PRE_P[i][j].first = -1 , PRE_P[i][j].second = -1 ;

  SP_Q initial ;
  initial.POINT.first = h -1  ;  initial.POINT.second  = 0 ;
  initial.PRE.first   = -1    ;  initial.PRE.second   = -1 ;  initial.SP = 0 ;
  q.push(initial);

  while( !q.empty() ) {
    SP_Q temp = q.top() ; q.pop() ;
    pair<int,int > point , pre ;
    point.first = temp.POINT.first  ;  point.second = temp.POINT.second ;
    pre.first   = temp.PRE.first    ;  pre.second   = temp.PRE.second   ;
    int x = point.first , y = point.second ;
    int sp = temp.SP ;

    if( check[x][y] ) continue ;
    check[x][y] = true ;
    // printf("travel %d %d %d\n",x,y,sp);
    PRE_P[x][y].first  = pre.first  ;
    PRE_P[x][y].second = pre.second ;

    ANS_SP[x][y] = sp ;
    // greedy
    if ( x == 0 and y == w - 1) break ;
    // travel
    SP_Q TMP ;
    TMP.PRE.first = x   ; TMP.PRE.second = y ;
    if ( x - 1 >= 0) if(cliff[x-1][y] == '.'){
      TMP.POINT.first = x - 1;  TMP.POINT.second = y ;      TMP.SP  = sp + 5 ;
      q.push(TMP) ;
     }
    if ( y - 1 >= 0) if(cliff[x][y-1] == '.'){
      TMP.POINT.first = x ;     TMP.POINT.second = y - 1 ;  TMP.SP  = sp + 1 ;
      q.push(TMP) ;
     }
    if ( x + 1 <  h) if(cliff[x+1][y] == '.'){
      TMP.POINT.first = x + 1;  TMP.POINT.second = y  ;     TMP.SP  = sp  ;
      q.push(TMP) ;
     }
    if ( y + 1 <  w) if(cliff[x][y+1] == '.'){
      TMP.POINT.first = x ;     TMP.POINT.second = y + 1 ;  TMP.SP  = sp + 1 ;
      q.push(TMP) ;
     }
  }

  stack< pair<int,int> > ANS ;
  int N = 0 , M = w - 1 ;
  if(ANS_SP[N][M] == 0) printf("-1");
  else printf("%d \n",ANS_SP[N][M]);
  // while( PRE_P[N][M].first != -1 and PRE_P[N][M].second != -1) {
  //   ANS.push( make_pair(N,M) ) ;
  //   int T_N = PRE_P[N][M].first , T_M = PRE_P[N][M].second ;
  //   N = T_N ;M = T_M ;
  // }

  // for(;!ANS.empty(); ANS.pop())
  //   printf("P : %d %d | ",ANS.top().first,ANS.top().second);
}