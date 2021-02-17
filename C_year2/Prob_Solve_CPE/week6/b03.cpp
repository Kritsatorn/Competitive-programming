#include<bits/stdc++.h>
using namespace std;

struct vertex {
  int shortest_path;
  int name_vertex ;
  int pre = 0 ;
  bool operator<(const vertex& a) const{
    return shortest_path > a.shortest_path;
  }
} ;
struct edge {
  int to;
  int weight;
};

priority_queue<vertex> q;
vector<struct edge> edges[100010];
int n ,m ,check[100010] ,pre[100010];
pair<int,int> pre_w[100010] ;
int main(int argc, char const *argv[])
{
  int from ,to ,weight;
  int temp_pre;

  scanf("%d %d",&n,&m);

  for(int i=0 ; i<=n ;i++) pre[i] = -1;
  for(int i=0 ; i<=n ;i++) pre_w[i] = make_pair(-1,0);
  pre[1] = 0;
  pre_w[1] = make_pair(0,0);
  for (int i=0 ; i<m ;i++ ){
    scanf("%d %d %d",&from,&to,&weight);
    struct edge temp ;
    temp.to = to; temp.weight = weight;
    edges[from].push_back(temp);
    temp.to = from ;
    edges[to].push_back(temp);
  }

  struct vertex initial ;
  initial.name_vertex = 1;
  initial.shortest_path = 0;
  initial.pre = 0;
  q.push(initial);

  while(!q.empty()) {
    struct vertex temp = q.top() ;  q.pop() ;
    int vertex = temp.name_vertex;
    int distance = temp.shortest_path;
    int previous = temp.pre;
    if ( check[vertex] ) continue;
      check[vertex] = 1;

    pre[vertex] = previous ;
    pre_w[vertex] = make_pair(previous,distance);
    if(vertex == n) break;

    while(!edges[vertex].empty()) {
      struct edge temp_edge = edges[vertex].back() ;  edges[vertex].pop_back();
      if (check[temp_edge.to]) continue;

      struct vertex temp_vertex ;
      temp_vertex.name_vertex = temp_edge.to ;
      temp_vertex.shortest_path = temp_edge.weight + distance;
      temp_vertex.pre = vertex ;
      // printf("q of %d : %d %d \n",vertex,temp_vertex.name_vertex,temp_vertex.shortest_path);
      q.push(temp_vertex);
    }
  }

  printf("%d",pre_w[n].second);
  // stack<int> ans;
  // while(pre[n] != -1) {
  //   // printf("%d ",n);
  //   ans.push(n);
  //   n = pre[n];
  // }

  // if( ans.empty() )
  //   printf("-1");
  // else
  //   for(;!ans.empty(); ans.pop())
  //     printf("%d ",ans.top());

  return 0;
}
