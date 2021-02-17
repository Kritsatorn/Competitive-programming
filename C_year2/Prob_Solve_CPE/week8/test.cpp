#include<bits/stdc++.h>
using namespace std;
struct Point{
  int x,y,dis ;
   bool operator<(const Point& rhs) const
    {
        return dis > rhs.dis;
    }
}point ;
main() {
  priority_queue<Point> pq;
  Point tmp ;
  tmp.x = 0 ; tmp.y = 1 ;
  tmp.dis = 10 ;
  pq.push(tmp);
  tmp.dis = 100;
  pq.push(tmp);
  tmp.dis=1000;
  pq.push(tmp);
  while (!pq.empty())
  {
    tmp = pq.top();   pq.pop();
    printf("%d ",tmp.dis);
  }
  
}