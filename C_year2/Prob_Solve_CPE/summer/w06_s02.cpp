#include<bits/stdc++.h>
using namespace std ;
struct edge{ int u , w ;} ;
vector <struct edge> Edge[210] ;
int check[210] , MAX_W , A , B , V , E , u , v , w  , MST , Count_E;
bool Fuck(int u , int v) {
  check[u] = true ;
  if( u == v ) return 1 ;
  for(int i=0 ; i < Edge[u].size() ; i ++)
    if ( !check[ Edge[u][i].u ] && Fuck( Edge[u][i].u , v ) ) {
      if ( Edge[u][i].w > MAX_W ) {
        MAX_W = Edge[u][i].w ;
        A = u ;
        B = Edge[u][i].u ;
      }
      return 1;
    }
    return 0 ;
}
void DEL(int u , int v) {
  for( int i=0 ; i < Edge[u].size() ; i++) {
    if ( Edge[u][i].u == v ) {
      swap( Edge[u][i] , Edge[u].back() ) ;
      Edge[u].pop_back() ;
      break ;
    }
  }
  return ;
}
main() {
  scanf("%d %d",&V , &E) ;
  while( E-- ) {
    scanf("%d %d %d",&u,&v,&w); u-- ; v-- ;

    MAX_W = 0 ;
    memset(check,false,sizeof(check));
    // fill( check, check + V, false );
    if ( Fuck( u ,v ) ) {
      if ( MAX_W > w ) {
        MST -= MAX_W - w ;
        DEL( A , B );
        DEL( B , A );
        Edge[u].push_back( (edge){ v , w} );
        Edge[V].push_back( (edge){ u , w} );
      }
    } else {
      Count_E++ ;
      MST += w ;
      Edge[u].push_back( (edge){ v , w} );
      Edge[V].push_back( (edge){ u , w} );
    }
    printf("%d\n" , Count_E == V - 1 ? MST : -1 );
  }
}