#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi; 
const int sizeN = 100010  ;
vector< pair<int, int> > G[sizeN] ;
struct dij_path {
  int Node , distance , preNode ;
  bool operator<(const dij_path& a) const
    {
        return distance > a.distance;
    }
};

dij_path createDij_Path(int Node ,int distance , int preNode ) {
  dij_path toPushPQ ;
  toPushPQ.Node = Node ;
  toPushPQ.distance = distance;
  toPushPQ.preNode = preNode;
  return toPushPQ ;
}

void solve(int N)
{
  priority_queue<dij_path> pq; 
  int   backTrack[sizeN] = {-1} ;
  bool  visited[sizeN] = {false} ;
  backTrack[0] = -1 ;

  pq.push( createDij_Path(1,0,0) ) ;

  while( !pq.empty() ) {
    dij_path temp = pq.top() ; pq.pop() ;
    int currentNode = temp.Node ;
    int distance = temp.distance ;
    int preNode = temp.preNode ;

    if ( visited[currentNode] ) continue;
    visited[currentNode] = true ;
    backTrack[currentNode] = preNode ;

    if ( currentNode == N ) break;

    for ( auto &V : G[currentNode] ) {
      int to = V.first ;
      int weightV  = V.second ;
      if ( visited[to] ) continue;
      pq.push(createDij_Path(to , distance + weightV , currentNode ) );
    }

  }

  int Ans = N ;
  stack<int> printAns ;
  do  {
    printAns.push(Ans);
    Ans = backTrack[Ans];
  } while(backTrack[Ans] != -1 );

  if( printAns.top() == N ) {
    cout << "-1" << "\n" ;
    return ;
  }

  while(!printAns.empty())
  cout << printAns.top() << " " , printAns.pop() ;
  cout << "\n" ;

  return;
}
int main()
{
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; i++)
  {
    int from, to, weight;
    cin >> from >> to >> weight;
    G[from].push_back(make_pair(to, weight));
    G[to].push_back(make_pair(from, weight));
  }
  solve(N);
  return 0;
}
