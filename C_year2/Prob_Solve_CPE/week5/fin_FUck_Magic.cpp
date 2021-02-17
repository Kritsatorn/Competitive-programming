#include<stdio.h>
#include<algorithm>
#include <utility>
#include<vector>
#include<queue>

#define REP(i, b, n) for (int i = b; i < n; i++)
#define REPI(i, b, n) for (int i = b; i <= n; i++)
#define rep(i, n) REP(i, 0, n)
#define repi(i, n) REPI(i, 0, n)

using namespace std ;

int n,m,k,k_point,h ;
main() {
  scanf("%d %d %d %d",&n,&m,&k,&h);
  if ( k == 1 ) scanf("%d",&k_point);

  vector< pair<int,int> > v[1000010] ;
  int a,b,c ;
  rep(i,m) {
    scanf("%d %d %d",&a,&b,&c);
    v[a].push_back( make_pair(b,c) );
    v[b].push_back( make_pair(a,c) );
  }

  queue< pair<int,int> > q ;
  q.push( make_pair(1,0) ) ;
  rep(i,h) {
    queue< pair<int,int> > q2 = q , empty ;
    bool check[1000010][2] = {0} ;
    swap(q,empty) ;

    while( !q2.empty() ) {
      pair<int,int> point = q2.front() ;  q2.pop( ) ;
      int node = point.first ;
      int magic = point.second ;

      if( check[node][magic] ) continue ;
      check[node][magic] = true ;

      rep(i,v[node].size()) {
        
      }

    }
  }


}