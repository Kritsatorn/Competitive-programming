#include<bits/stdc++.h>
using namespace std ;
struct Work {
  int S , E ,idx;
} ;
bool cmp (Work a, Work b) { return a.E < b.E;}
main() {
  int test_case ,count_case = 0;
  scanf("%d",&test_case);
  while (count_case++ < test_case ) {
    int n ,s,e;
    Work work[1010] ;
    vector<int> Node[1010] ;
    scanf("%d",&n) ;
    for(int i=0 ; i <n ; i++)
      scanf("%d %d",&work[i].S,&work[i].E) , work[i].idx = i ;
  // ------
    sort(work,work+n,cmp);
    for(int i=0 ; i <n ; i++) {
      // printf("%d %d\n",work[i].S,work[i].E) ;
      for( int j =0 ; j < i ; j ++) {
        int x , y ;
        // opposite
        x = work[i].idx ; y = work[j].idx ;
        if ( work[i].S < work[j].E) {
          Node[x].push_back(y) ;
          Node[y].push_back(x) ;
        }
      }
    }
    //--------
    int ans[1010] ;
    bool can = true , check[1010] ;
    memset(ans, -1, sizeof(ans));
    memset(check, false, sizeof(check));
    // for(int i=0 ; i <n ; i++){
    //   printf("Node %d : ",i);
    //   for(int j=0 ; j< Node[i].size() ; j ++)
    //     printf("%d ",Node[i][j]);
    //   printf("\n");
    // }

    for(int i=0 ; i <n ; i++) {
      if ( ans[i] != -1 ) continue ;
      ans[i] = 1 ;
      queue<int> q ;  q.push(i) ;
      while( !q.empty() ) {
        int u = q.front() ;   q.pop() ;
        if ( check[u] ) continue;
        check[u] = true ;
        for(int v=0 ; v < Node[u].size() ; v++) {
          if ( ans[Node[u][v]] == -1 ) {
            ans[Node[u][v]] = 1 - ans[u] ; q.push(Node[u][v]) ;
          }
          else if ( ans[Node[u][v]] == ans[u]) {
            // printf("sad %d %d",u,Node[u][v]);
            can = false; goto b;}
        }
      }
    }
    b:;
    printf("Case #%d: ",count_case);
    if ( can )
      for(int i=0 ; i<n ; i++)
      if( ans[i] )
        printf("C");
      else
        printf("J");
    else
      printf("IMPOSSIBLE") ;
    printf("\n");
 // ---
  }
}