#include <bits/stdc++.h>
using namespace std;

int N , M , L , people[100010] ;

class Graph {
	int V;
	list<pair<int, int> >* adj;

public:
	Graph(int V);
	void addEdgeRev(int u, int v, int w);
	void shortestPath(int s);
};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<pair<int, int>>[V];
}

void Graph::addEdgeRev(int u, int v, int w) {
	adj[v].push_back(make_pair(u, w));
}

void Graph::shortestPath(int dest)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	vector<int> dist(V, INT_MAX);
	pq.push(make_pair(0, dest));
	dist[dest] = 0;

	while (!pq.empty()) {

		int u = pq.top().second;
		pq.pop();

		list<pair<int, int> >::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i) {

			int v = (*i).first;
			int weight = (*i).second;

			if (dist[v] > dist[u] + weight) {
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}
		}
	}

  int SUM = 0 ;
	for (int i = 1; i < V; ++i) {
    int Cost = people[i+1] > L ? L : people[i+1] ;
    SUM += Cost * dist[i];
  }
  cout << SUM << endl ;

}

int main()
{

  int from , to , weight ;
  cin >> N >> M >> L ;
	int V = N;
	Graph g(V);
  for(int n=1 ; n<=N ; n++) scanf("%d",&people[n]);
  for (int m=0 ; m<M ;m++ ) {
    scanf("%d %d %d",&from,&to,&weight);
    from -- ; to -- ;
    g.addEdgeRev(from, to, weight);
    g.addEdgeRev(to, from, weight);
  }
	g.shortestPath(0);

	return 0;
}
