#include<bits/stdc++.h>
using namespace std;
struct Point{
  int x,y,dis ;
  bool operator<(const Point& rhs) const
    {
        return dis > rhs.dis;
    }
}point ;
    int arr[1010][1010] ;
    bool visited[1010][1010];
main() {

  int T ;
  int dir[4][2] = { {-1,0} , {1,0} , {0,-1}, {0,1}};
  cin >> T ;
  for(int t = 0 ; t < T ; ++ t) {
    int N, M;

    cin >> N >> M ;
    for(int n=0 ; n<N ; n++)
      for(int m=0 ; m<M ; m++)
        cin >> arr[n][m];
    memset(visited,false,sizeof(visited));
    priority_queue<Point> pq;
    Point tmp ;   tmp.x = 0 ; tmp.y = 0;
    tmp.dis = arr[0][0];
    pq.push(tmp);   visited[0][0] = true ;

    while( !pq.empty() ) {
      tmp = pq.top() ;  pq.pop();

      if ( tmp.x == N-1 && tmp.y == M-1) {
        cout << tmp.dis << endl ; break;
      }

      for(int i=0 ; i <4 ; i++) {
        int new_x = tmp.x + dir[i][0] ;
        int new_y = tmp.y + dir[i][1] ;

        if (
          new_x >= 0 && new_x < N &&
          new_y >= 0 && new_y < M &&  !visited[new_x][new_y]
        ) {
          visited[new_x][new_y] = true ;
          Point p ; p.x = new_x ; p.y = new_y ;
          p.dis = tmp.dis + arr[new_x][new_y] ;
          pq.push(p);
        }
      }
    }
  }
}