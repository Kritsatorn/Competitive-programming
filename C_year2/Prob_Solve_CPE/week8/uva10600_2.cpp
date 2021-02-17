#include<bits/stdc++.h>
using namespace std;
struct Point{
  int x,y,dis ;
  bool operator<(const Point& rhs) const
    {
        return dis > rhs.dis;
    }
}point ;
bool cmp (Point a , Point b) { return a.dis < b.dis ;}
int N,M,from , to ,dis ;
int Find(vector<Point>  vt,int P_iniitial) {
    int rank[110],head[110] ;
    memset(rank ,  1 , sizeof(rank) );
    for(int n=1 ; n<= N ; n++) head[n] = n ;
    int ANS = 0;
    // --
    int m = P_iniitial ;
    from = vt[m].x ;  to = vt[m].y ; dis = vt[m].dis ;
    rank[from] += rank[to] ; head[to] = from ;
    ANS  += dis ;
    // --

    for( int m=0 ; m < M ; m++ ) {
      from = vt[m].x ;  to = vt[m].y ; dis = vt[m].dis ;
      // find head
      // printf("path %d from %d  to %d cost %d \n",m,from,to,dis);
      int Head1 = head[from] , Head2 = head[to] ;
      while( Head1 != head[Head1]) Head1 = head[Head1] ;
      while( Head2 != head[Head2]) Head2 = head[Head2] ;
      // printf("HEad %d %d\n",Head1,Head2);
      if (  Head1 != Head2 ) {
        if ( rank[Head1] >= rank[Head2] )
          rank[Head1] += rank[Head2] , head[Head2] = Head1 ;
        else
          rank[Head2] += rank[Head1] , head[Head1] = Head2 ;
        ANS += dis ;
      }
    }
    // cout << ANS << endl ;
    return ANS ;
}
main(){
  int T ;
  cin >> T ;
  for(int t=0 ; t<T ; ++t) {
    // int N,M ;
    cin >> N >> M ;
    Point tmp ;
    // int from , to ,dis ;
    vector<Point> vt ;
    for(int m=0 ; m < M ; m++) {
      cin >> from >> to >> dis ;
      tmp.x = from ;  tmp.y = to ; tmp.dis = dis ;
      vt.push_back(tmp);
    }
    sort(vt.begin() , vt.end() , cmp );
    priority_queue <int, vector<int>, greater<int>> pq;
    for(int m=0 ; m < M ; m++) pq.push(Find(vt,m));
    cout << pq.top() << " " ;
    for(int i=0 ; i<N-1 ; i++)pq.pop() ;
    cout << pq.top() << endl ;
  }
}