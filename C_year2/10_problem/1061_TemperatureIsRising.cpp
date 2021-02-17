#include<stdio.h>
int n ,max ,x_start ,y_start ;
int arr[22][22] ,check[22][22];

void dfs(int x,int y) {
  if (arr[x][y] == 100 || check[x][y] == 1)
    return ;

  max = arr[x][y] > max ? arr[x][y]:max;
  check[x][y] = 1;

  if (x+1 <= n)
    if ( arr[x][y] < arr[x+1][y]) dfs(x+1,y);
  if (x-1 >= 0)
    if ( arr[x][y] < arr[x-1][y]) dfs(x-1,y);
  if (y+1 <= n)
    if ( arr[x][y] < arr[x][y+1]) dfs(x,y+1);
  if(y-1 >= 0)
    if ( arr[x][y] < arr[x][y-1]) dfs(x,y-1);

  check[x][y] = 0;
  return ;
}

int main(int argc, char const *argv[])
{

  scanf("%d",&n);
  scanf("%d %d",&y_start,&x_start);
  for (int i=1 ; i<=n ; i++ ){
    for (int j=1 ; j<=n ;j++)
      scanf("%d",&arr[i][j]);
  }
  dfs(x_start,y_start);
  printf("%d",max);
  return 0;
}
