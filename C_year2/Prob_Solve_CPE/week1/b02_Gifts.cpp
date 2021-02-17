#include<stdio.h>
int main(int argc, char const *argv[])
{
  int n,ans=0;
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
    int x;
    scanf("%d",&x);
    ans += x > 0 ? x : 0;
  }
  printf("%d",ans);
  return 0;
}
