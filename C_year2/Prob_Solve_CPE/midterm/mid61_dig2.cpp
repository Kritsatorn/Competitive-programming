#include<bits/stdc++.h>
using namespace std;
int n, m, a, b, ax, by;
char arr[51][51];
// 1 == -- || 2 == |
int bfs(int x, int y) {
  // if ( x < 0 || x >= n) return 0;
  // if ( y < 0 || y >= m) return 0;
  int level = -1 ;
  bool check[51][51] ;
  memset(check, false, sizeof(check));
  queue< pair<int,int> > q ;
  q.push( make_pair(x,y) );
  while( !q.empty() ) {
    queue< pair<int,int> > qtemp;
    swap(q,qtemp);
    level++ ;
    while( !qtemp.empty() ) {
      int x = qtemp.front().first   ;
      int y = qtemp.front().second  ;
      qtemp.pop();
    // printf("travel %d %d  : %c \n",x,y,arr[x][y]);
      if ( x == ax && y == by) return level;

      if ( check[x][y] ) continue;
      check[x][y] = 1;
      if ( x < 0 || x >= n)   continue;
      if ( y < 0 || y >= m)   continue;
  // 1 == -- || 2 == |
      if ( arr[x][y] == '1') {
        if ( arr[x][y+1] == '.' && check[x][y-1] ) q.push( make_pair(x,y+1) );
        if ( arr[x][y-1] == '.' && check[x][y+1] ) q.push( make_pair(x,y-1) );
        continue;
      }

      if ( arr[x][y] == '2') {
        if ( arr[x+1][y] == '.' && check[x-1][y] ) q.push( make_pair(x+1,y) );
        if ( arr[x-1][y] == '.' && check[x+1][y] ) q.push( make_pair(x-1,y) );
        continue;
      }

      if ( arr[x+1][y] == '.' || arr[x+1][y] == '1' || arr[x+1][y] == '2')
      q.push( make_pair(x+1,y) );
      if ( arr[x][y+1] == '.' || arr[x][y+1] == '1' || arr[x][y+1] == '2')
      q.push( make_pair(x,y+1) );
      if ( arr[x-1][y] == '.' || arr[x-1][y] == '1' || arr[x-1][y] == '2')
      q.push( make_pair(x-1,y) );
      if ( arr[x][y-1] == '.' || arr[x][y-1] == '1' || arr[x][y-1] == '2')
      q.push( make_pair(x,y-1) );
    }
  }
  return INT_MAX ;
}
int main(int argc, char const *argv[])
{
  scanf("%d %d",&n,&m);
  scanf("%d %d %d %d",&a,&b,&ax,&by);
  a-- ; b-- ; ax -- ; by -- ;
  for(int i=0; i<n; i++)
    scanf("%s",arr[i]);

  int minn = INT_MAX , k;
  for(int i=0 ; i<n ; i++)
    for(int j = 0 ; j < m ; j ++)
      if ( arr[i][j] == '*') {
        if ( arr[i][j-1] == '.' || arr[i][j+1] == '.') {
          arr[i][j] = '1' ;  k = bfs(a,b);
          minn = min(k,minn);
        }
        if ( arr[i-1][j] == '.' || arr[i+1][j] == '.') {
          arr[i][j] = '2' ;  k = bfs(a,b);
          minn = min(k,minn);
        }
        arr[i][j] = '*' ;
      }
  if( minn == INT_MAX )
    printf("-1");
  else printf("%d",minn);
  return 0;
}

