#include<stdio.h>
int arr[4] ,ans[4] ,n ,type ,min;
int main(int argc, char const *argv[])
{

  scanf("%d %d %d",&arr[0],&arr[1],&arr[2]);
  scanf("%d",&n);
  for(int i=0; i<n ;i++) {
    scanf("%d",&type);
    switch(type) {
      case 1 : ans[0] += arr[0];
      break;
      case 2 : ans[1] += arr[1];
      break;
      case 3 : ans[2] += arr[2];
      break;
    }
  }
  min = ans[0];
  min = ans[1] < min ? ans[1] : min ;
  min = ans[2] < min ? ans[2] : min ;
  printf("%d",min);
  return 0;
}
