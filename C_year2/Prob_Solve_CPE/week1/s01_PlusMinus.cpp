#include<stdio.h>
char temp[10];
int n ,num ,num_temp ,ans;
int main(int argc, char const *argv[])
{
  scanf("%d",&n);
  scanf("%d",&num);
  ans = num ;
  for (int i=0 ;i<n-1 ;i++) {
    scanf("%c%c%c%d",&temp[0],&temp[1],&temp[2],&num_temp);
    switch(temp[1]) {
      case '+' : ans += num_temp;
      break;
      case '-' : ans -= num_temp;
      break;
    }
  }
  printf("%d",ans);
  return 0;
}
