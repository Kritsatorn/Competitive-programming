#include<stdio.h>
#include<math.h>
int cal_dart(int x ,int y) {
  float distance;
  distance = sqrt( pow( (x-0),2) +  pow( (y-0),2));
  if ( distance <= 2)
    return 5;
  else if ( distance <= 4)
    return 4;
  else if ( distance <= 6)
    return 3;
  else if ( distance <= 8)
    return 2;
  else if ( distance <= 10)
    return 1;
  else
    return 0;
}

int main(int argc, char const *argv[])
{
  int n ,x ,y ,ans = 0;
  scanf("%d",&n);
  for (int i=0 ; i<n ;i++ ){
    scanf("%d %d",&x,&y);
    ans += cal_dart(x,y);
  }
  printf("%d",ans);
  return 0;
}
