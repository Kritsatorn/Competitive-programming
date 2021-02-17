#include<stdio.h>
#include<string.h>
#include<math.h>
int x ,y ,N_count , S_count ,W_count ,E_count;
int main(int argc, char const *argv[])
{
  char s[1000];
  int k ;
  scanf("%s",s);
  scanf("%d",&k);
  for (int i=0 ; i< strlen(s) ;i++) {
    switch(s[i]) {
      case 'N' : N_count += 1;
      break;
      case 'S' : S_count += 1;
      break;
      case 'W' : W_count += 1;
      break;
      case 'E' : E_count += 1;
      break;
    }
  }

  // greedy ver
  int x_more = W_count > E_count ? W_count : E_count;
  int x_less = W_count > E_count ? E_count : W_count;

  int y_more = N_count > S_count ? N_count : S_count;
  int y_less = N_count > S_count ? S_count : N_count;

  // printf("%d %d %d %d\n",x_more,x_less,y_more,y_less);
  y_more = x_less + y_less + x_more + y_more > k ?
    y_more - ( x_less + y_less + x_more > k ? 0 : k - (x_less + y_less + x_more) ) : 0;
  x_more = x_less + y_less + x_more > k ?
    x_more - ( x_less + y_less > k ? 0 : k - (x_less + y_less) ) : 0;

  y_less = x_less + y_less > k ? y_less - ( x_less > k ? 0 : k - x_less) : 0 ;
  x_less = x_less > k ? x_less - k : 0;

  // printf("%d %d %d %d\n",x_more,x_less,y_more,y_less);
  int ans = ( x_more - x_less ) + ( y_more - y_less);
  printf("%d",ans*2);
  return 0;
}
