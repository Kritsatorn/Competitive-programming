#include <bits/stdc++.h>
using namespace std;
struct Node
{
	public:
		int id;
		vector<Node*> adj;
		Node (int id) : id(id) {}
};

class Graph
{
	public:
		Graph() {}
		~Graph();
		Node* add (int v);
		void addEdge (int begin, int end, bool directed);
		Node* firstNode();
    vector<int> result;
    void solve(int n);
    void visit(int n, bool *visited);
	private:
		Node* getNode (int v);
		map<int, Node*> NodeMap;
		vector<Node*> allNodees;
};

Graph::~Graph()
{
	for (int i = 0; i < allNodees.size(); i++)
		delete allNodees[i];
}

Node* Graph::add (int v) {
	Node* newv = new Node (v);
	allNodees.push_back (newv);
	NodeMap.insert (pair<int, Node*> (v, newv));
	return newv;
}

void Graph::addEdge (int begin, int end, bool directed = false)
{
	Node* v = getNode (begin);
	Node* w = getNode (end);
	v->adj.push_back (w);
	if (!directed)
		w->adj.push_back (v);
}

Node* Graph::getNode (int v)
{
	map<int, Node*>::iterator it = NodeMap.find (v);
	if (it == NodeMap.end()) return add (v);
	return (*it).second;
}

Node* Graph::firstNode() {
	return allNodees[0];
}

void Graph::solve(int n)
{
  Node* v;  bool nodes[n+1] ,visited[n+1];
  fill (nodes, nodes + n + 1, true);
  fill (visited, visited + n + 1, false);

  for (int i = 1; i <= n; i++) {
    v = getNode(i);
    for (int j = 0, sz = v->adj.size(); j < sz; j++) nodes[v->adj[j]->id] = false;
  }

  for (int i = 1; i <= n; i++)
    if (nodes[i]) visit(i, visited);

}

void Graph::visit(int n, bool *visited)
{
  if (visited[n])
    return;
  visited[n] = true;
  Node* v = getNode(n);
  for (int i = 0, sz = v->adj.size(); i < sz; i++)
    visit(v->adj[i]->id, visited);

  result.push_back(n);
}

main()  {
  int n, m,a,b;
  while (cin >> n >> m) {
    if (n == 0 && m == 0) break;
    Graph graph;

    for (int i = 1; i <= n; i++) graph.add(i);

    while (m--)
      cin >> a >> b, graph.addEdge(b, a, true);

    graph.solve(n);
    for (int i = 0; i < n; i++) {
      if (i > 0) cout << " ";
      cout << graph.result[i];
    }
    cout << endl;
  }
}