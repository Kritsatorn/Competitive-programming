#include<bits/stdc++.h>
using namespace std ;
int n ,m ;
vector<int> v[100010];
vector< pair<int,int> > p ;
bool Bipartite() {
   int colorA[100010] ;
   for (int i = 1; i <= n; i++)
      colorA[i] = -1;
   colorA[1] = 1; //Assign a color to the source vertex
   queue <int> q; //Create a queue of vertex numbers and enqueue source vertex for BFS traversal
   q.push(1);
   while (!q.empty()) {
      int w = q.front(); //dequeue a vertex
      q.pop();
      // printf("w = %d : ",w);
      for (int i = 0; i < v[w].size() ; i++) {
        // printf("%d ",v[w][i]);
         if ( colorA[ v[w][i] ] == -1 ) {
          //  printf(" d ");
            colorA[ v[w][i] ] = 1 - colorA[w];
            q.push( v[w][i] );
         } else if ( colorA[ v[w][i] ] == colorA[w] )
            return false;
      }
      // printf("\n");
   }
   return true;
}
main() {
  scanf("%d %d",&n,&m);
  for(int i=0 ; i<m;i++) {
      int a,b;
      scanf("%d %d",&a,&b);
      v[a].push_back(b);
      v[b].push_back(a);
      p.push_back( make_pair(a,b) );
  }
  for(int i=0;i<m;i++) {
    int a , b;
    a = p[i].first; b = p[i].second ;
    v[a].erase(remove(v[a].begin(), v[a].end() , b) , v[a].end());
    v[b].erase(remove(v[b].begin(), v[b].end() , a) , v[b].end());
    if ( Bipartite() ) {
      printf("%d %d",a,b);
      break;
    }
    v[a].push_back(b);
      v[b].push_back(a);
  }

}