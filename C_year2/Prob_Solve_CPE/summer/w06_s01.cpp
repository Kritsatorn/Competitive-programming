#include<bits/stdc++.h>
using namespace std;
int main()
{
  int test_case ,count_case = 0;
  int N , idx , ND[1010] , D[1010][10] ;
  bool VIS[1010];
  queue<int> q;
  scanf("%d",&test_case);
  while (count_case++ < test_case ) {
    printf("Case #%d: ",count_case);
    queue<int> q_temp ; swap(q,q_temp);
    scanf("%d",&N) ;
    for(int n=0 ; n<N ; n++) {
      scanf("%d",&ND[n]) ;
      for(int nd=0 ; nd<ND[n] ; nd++) {
        scanf("%d",&D[n][nd]) , D[n][nd] -- ;
      }
    }
    for(int k=0 ; k<N ; k++) {
      memset(VIS,0,sizeof(VIS)) ;
      q.push(k) ;
      while( !q.empty() ) {
        idx = q.front() , q.pop() ;
        if( VIS[idx] ) {
          printf("Yes\n");
          goto Done;
        }
        VIS[idx] = 1 ;
        for(int i=0 ; i < ND[idx] ; i++) q.push(D[idx][i]);
      }
    }
    printf("No\n") ;
    Done: ;
  }
}