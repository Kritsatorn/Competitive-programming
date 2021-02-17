#include<stdio.h>
#include<string.h>
int main(int argc, char const *argv[])
{
  char s[1000];
  int x=0 ,y=0;
  scanf("%s",s);

  for (int i=0 ; i< strlen(s) ;i++) {
    switch(s[i]) {
      case 'N' : y += 1;
      break;
      case 'S' : y -= 1;
      break;
      case 'W' : x -= 1;
      break;
      case 'E' : x += 1;
      break;
      case 'Z' : x = 0 ; y = 0 ;
      break;
    }
  }
  printf("%d %d",x,y);
  return 0;
}
