#include<bits/stdc++.h>
using namespace std ;
// vector< pair<int,int> > node[1010] ;
struct Edge{
  int X , Y, W ;
  bool operator<(const Edge& a) const { return W < a.W; }
}edge;
vector<struct Edge> vect_edge ;

int boss[100010] ;
int n , m ;
main() {
  int a, b, w ;
  scanf("%d %d",&n,&m);
  for(int i=0 ; i<m ; i++) {
    scanf("%d %d %d",&a,&b,&w);
    edge.X = a ;  edge.Y = b ;  edge.W = w ;
    vect_edge.push_back(edge) ;
  }
  sort(vect_edge.begin() , vect_edge.end()) ;
  int sum_w = 0 ;
  for(int i=0 ; i<m ; i++){
    // printf("%d %d %d\n",vect_edge[i].X,vect_edge[i].Y,vect_edge[i].W);
    int x ,y ,w ,xrank ,yrank ;
    x = vect_edge[i].X ;  xrank = 0 ;
    y = vect_edge[i].Y ;  yrank = 0 ;
    w = vect_edge[i].W ;
    while( boss[x] != 0)
      x = boss[x] , xrank++ ;
    while( boss[y] != 0)
      y = boss[y] , yrank++ ;

    if ( x != y)
          if ( xrank >= yrank) boss[y] = x , sum_w += w ;
          else boss[x] = y , sum_w += w ;
  }
  printf("%d",sum_w);

}