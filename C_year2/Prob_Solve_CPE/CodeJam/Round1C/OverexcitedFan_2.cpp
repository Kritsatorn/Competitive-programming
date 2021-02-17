#include<bits/stdc++.h>
using namespace std ;
int X , Y , T , ANS , DirCat[1010][3] , check[1010][1010] ;
int Dir[4][2] = { {-1,0} , {1,0} , {0,1} , {0,-1}  } ;
queue< pair<int,int> > q ;
main() {
  int test_case ,count_case = 0;
  scanf("%d",&test_case);
  while (count_case++ < test_case ) {
    char S[1010] ;
    scanf("%d %d",&Y,&X);
    scanf("%s",S);
    T = strlen(S) ;
    queue< pair<int,int> > q ;
    q.push( make_pair(0,0) ) ;
    check[0][0] = 1;
    for(int t=0 ; t<=T ; t ++ ) {
      // move
      queue< pair<int,int> > q_temp ;
      swap(q,q_temp) ;
      while(!q_temp.empty()) {
        pair<int,int> temp = q_temp.front() ; q_temp.pop() ;
        int PX = temp.first , PY = temp.second ;
        printf("cat %d %d  :%d %d %d \n",X,Y,t,PX,PY) ;
        if ( PX  == X && PY == Y) {ANS = t + 1 ; goto ans;}
        for(int i=0; i<=4; i++) {
          if(check[PX + Dir[i][0]][PY + Dir[i][1]] != 1 )
          q.push( make_pair(PX + Dir[i][0],PY + Dir[i][1]) )
          , check[PX + Dir[i][0]][PY + Dir[i][1]] = 1;
        }
      }
      // cat move
      if( t!= T && t!= -1)
      switch(S[t]) {
        case 'W' : X += 0 ; Y += -1 ;
        break ;
        case 'N' : X += 1 ; Y += 0 ;
        break ;
        case 'E' : X += 0 ; Y += 1 ;
        break ;
        case 'S' : X += -1 ; Y += 0 ;
        break ;
      }
    }
    printf("ad");
    ans: ;
    printf("asds%d\n",ANS) ;
  }
}