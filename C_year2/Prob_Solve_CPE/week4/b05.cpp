#include <iostream>
#include<stdio.h>
#include <queue>
#include<vector>
using namespace std;
int n;
vector<int> v[100010];
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
int main(int argc, char const *argv[])
{
  int k ;
  scanf("%d",&k);
  for(int l=0 ; l<k ;l++ ) {
    int m ;
    scanf("%d %d",&n,&m);
    for(int i=0 ;i<m ;i++) {
      int a,b;
      scanf("%d %d",&a,&b);
      v[a].push_back(b);
      v[b].push_back(a);
    }

    if ( Bipartite() )
      printf("yes \n");
    else printf("no \n");

    for(int i=0;i<=n;i++)
      v[i].clear();
  }
  return 0;
}
