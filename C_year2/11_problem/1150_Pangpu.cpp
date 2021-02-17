#include<stdio.h>
int n ,arr[1001] ,max;
bool dp[1002][60004];
int main(int argc, char const *argv[])
{
  scanf("%d",&n);
  for (int i=1; i<=n ;i++)
    scanf("%d",&arr[i]);
// initial everything plus 30000
  for (int i = 1 ; i <= n ; i++)
    dp[i][0 + 30000] = true;
  dp[0][arr[0] + 30000] = true;

  for (int i = 1 ; i <= n ; i++) {
    for (int j = 0 ; j <= 60000 ; j++ ) {
      int real_num = j - 30000 ;

      int pick = real_num - arr[i] < -30000 ?
        real_num - arr[i] + 60001 : real_num - arr[i] > 30000 ?
        real_num - arr[i] - 60001 :  real_num - arr[i]  ;

      if (dp[i-1][pick + 30000] ) {
        dp[i][j] = true ;
        max = real_num > max ? real_num : max ;
      }
      if (dp[i-1][j])
        dp[i][j] = true ;
    }
  }

  printf("%d",max);
  return 0;
}
