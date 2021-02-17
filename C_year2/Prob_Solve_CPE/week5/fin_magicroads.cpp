#include<stdio.h>
#include<algorithm>
#include <utility>
#include<vector>
#include<set>
#include<queue>
using namespace std;
int n,m,k,nk,h;
bool check[1000010];
vector< pair<int,int> > v[1000010] ;
queue< pair<int,int> > q ;
set<int> sett ;
void dfs(int point , int health , bool magic) {

  if( health > h ) return ;
  if ( point == nk) magic = true ;
  // if( check[point] ) return ;
  // check[point] = 1 ;
  sett.insert(point) ;
  // printf("from %d : ",point);
  for(int i = 0 ; i < v[point].size() ; i ++ ) {
    if ( v[point][i].second == 1 )
      if ( !magic ) continue ;
    dfs(v[point][i].first,health+1,magic) ;
  }
  // printf("\n");
  // check[point] = 0 ;
  return ;
}
main() {
  scanf("%d %d %d %d",&n,&m,&k,&h);
  if( k ==  1 ) scanf("%d",&nk);

  int a , b , magic ;
  pair<int,int> p ;
  for(int i=0 ; i <m ; i ++) {
    scanf("%d %d %d",&a,&b,&magic) ;
    p = make_pair(b,magic) ;
    v[a].push_back(p) ;
    p = make_pair(a,magic) ;
    v[b].push_back(p) ;
    // printf("input : %d %d %d  \n",a,b,magic);
  }
  // for(int i=1 ; i <=n ; i ++)
  //   printf("%d : %d\n",i,v[i].size());

  q.push( make_pair(1,0));
  while( h-- > 0 ) {
    queue< pair<int,int> > q2 = q , empty;
    swap(q,empty);
    while( !q2.empty() ) {
      pair<int,int>  point = q2.front() ;  q2.pop() ;
      bool check[1000010][2] = {0} ;
      printf("%d ",point.first);
      for(int i=0 ; i < v[point.first].size() ; i++) {
        int mg = point.second ;
        if ( v[point.second][i].second == 1 )
          if ( !point.second ) continue ;
        if ( point.first == nk) mg = true;

        if( check[point.first][point.second] ) continue ;
        check[point.first][point.second] = 1 ;

        sett.insert(point.first) ;
        q.push( make_pair(point.first , mg ) ) ;
      }
    }

  }

  printf("%d",sett.size());
}