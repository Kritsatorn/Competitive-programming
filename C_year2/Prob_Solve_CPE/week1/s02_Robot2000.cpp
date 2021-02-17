#include<stdio.h>
#include<string.h>
#include<math.h>

char s[1010] ,ans[1010];
int direction ;
void append_R(int point_direction) {
  int move = point_direction >= direction ?
    point_direction - direction : 4 + point_direction - direction ;
  // printf("%d %d %d\n",point_direction,direction,move);
  direction = point_direction;
  for(int i =0 ; i < move ; i++)
    strcat(ans,"R");
  strcat(ans,"F");
  return ;
}

int main(int argc, char const *argv[])
{
  scanf("%s",s);
  for (int i=0 ; i<strlen(s) ;i++) {
    switch(s[i]) {
      case 'N' : append_R(0);
      break;
      case 'E' : append_R(1);
      break;
      case 'S' : append_R(2);
      break;
      case 'W' : append_R(3);
      break;
      case 'Z' : direction = 0;
      strcat(ans,"Z");
      break;
    }
  }
  printf("%s",ans);
  return 0;
}
