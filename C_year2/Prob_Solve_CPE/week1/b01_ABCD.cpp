#include<stdio.h>
int main(int argc, char const *argv[])
{
  int arr[5];
  int ans=0;
  for(int i=0 ; i<4;i++) {
    scanf("%d",&arr[i]);
    ans += arr[i];
  }
  printf("%d",ans);
  return 0;
}
