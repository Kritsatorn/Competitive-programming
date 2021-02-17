#include<bits/stdc++.h>
using namespace std ;
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
int N , M , L , people[100010] ,check[100010] ,pre[100010];
int SP(int start) {
  int ANS ;
  priority_queue<vertex> p ;
  swap(q,p);
  memset(check,0,sizeof(check)) ;
  struct vertex initial ;
  initial.name_vertex = start;
  initial.shortest_path = 0;
  initial.pre = 0;
  q.push(initial);

  while(!q.empty()) {
    struct vertex temp = q.top() ;  q.pop() ;
    int vertex = temp.name_vertex;
    int distance = temp.shortest_path;
    // int previous = temp.pre;
    if ( check[vertex] ) continue;
      check[vertex] = 1;

    // pre[vertex] = previous ;

    if(vertex == 1) {ANS = distance; break;}

    while(!edges[vertex].empty()) {
      struct edge temp_edge = edges[vertex].back() ;  edges[vertex].pop_back();
      if (check[temp_edge.to]) continue;

      struct vertex temp_vertex ;
      temp_vertex.name_vertex = temp_edge.to ;
      temp_vertex.shortest_path = temp_edge.weight + distance;
      // temp_vertex.pre = vertex ;
      // printf("q of %d : %d %d \n",vertex,temp_vertex.name_vertex,temp_vertex.shortest_path);
      q.push(temp_vertex);
    }
  }
  return ANS;
}
main() {
    int from , to , weight ;
    cin >> N >> M >> L ;
    for(int n=1 ; n<=N ; n++) scanf("%d",&people[n]);

    for (int m=0 ; m<M ;m++ ){
    scanf("%d %d %d",&from,&to,&weight);
    struct edge temp ;
    temp.to = to; temp.weight = weight;
    edges[from].push_back(temp);
    temp.to = from ;
    edges[to].push_back(temp);
  }
  // SP(3);s
  for(int n=1 ; n<=N ; n++){
    int Cost = SP(n) ;
    // cout << n << " : " << Cost << endl;
  }
  cout<< 0 << endl ;
}