#include<stdio.h>
#include<algorithm>
#include <utility>
#include<math.h>
#include<queue>
using namespace std;
int n ,r ,minn;
pair<int,int> p[1010];
queue<int> q;
int check[1010] ;

bool can_jump(int h,int k) {
  int x ,y ,xs ,ys ;
  x = p[h].first ;   y = p[h].second ;
  xs = p[k].first ;   ys = p[k].second ;
  int dis ;
  dis =  (x -xs) * (x -xs) +
                (y - ys) * (y - ys);
  if ( dis <= r*r) return true ;
  else return false ;
}

void bfs(int count) {

  queue<int> q1 ;
  q1 = q; q = queue<int> () ;
  while( !q1.empty() ) {
    int k ;
    k = q1.front() ; q1.pop() ;
    if ( check[k] ) continue;
    check[k] = 1;
    // end case
    if ( can_jump(k,n+1) ) {
      minn = minn > count+1 ? count+1 : minn ;
      return ;
    }
    //
    for(int i=1 ;i<=n ;i++ ){
      if ( check[i] ) continue ;
      if ( can_jump(k,i) ) q.push(i) ;
    }
  }
  if ( !q.empty() ) return bfs(count+1) ;
  return ;
}
int main(int argc, char const *argv[])
{
  scanf("%d %d",&n,&r);
  for(int i=1 ;i<=n ;i++) {
    int a,b;
    scanf("%d %d",&a,&b);
    p[i].first = a;
    p[i].second = b ;
  }
  p[0].first = 0;
  p[0].second = 0;
  p[n+1].first = 100;
  p[n+1].second = 100;
  minn = 9999999;
  q.push(0);
  bfs(0) ;
  if (minn == 9999999)
    printf("-1");
  else
    printf("%d ",minn);
  return 0;
}