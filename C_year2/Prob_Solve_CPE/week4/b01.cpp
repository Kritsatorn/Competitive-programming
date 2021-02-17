#include<stdio.h>
#include<vector>
using namespace std ;
vector<int> v[100010] ;
int check[100010];
void dfs(int node) {

  if(check[node] == 1) return ;
  check[node] = 1;
  for(int i=0 ;i< v[node].size() ;i++)
    dfs(v[node][i]);

  return ;
}
int main(int argc, char const *argv[])
{
  int n, m;
  scanf("%d %d",&n,&m);
  for(int i=0 ;i< m ;i++ ) {
    int a , b ;
    scanf("%d %d",&a,&b);
    v[a].push_back(b) ;
    v[b].push_back(a) ;
  }
  int count = 0 ;
  for(int i=1 ;i<=n ;i++) {
    if( check[i] ) continue ;
    count ++ ;
    dfs(i);
  }
  printf("%d",count) ;
  return 0;
}
