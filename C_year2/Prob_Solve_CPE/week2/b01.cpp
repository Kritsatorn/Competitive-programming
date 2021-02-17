#include<stdio.h>
#include<string.h>
char s[110];
int main(int argc, char const *argv[])
{
  scanf("%s",s);
  for(int i=0;i<strlen(s) ; i++)
    printf("%c",( (s[i]-'a') + 4 ) % 26 + 'a' );
  return 0;
}
