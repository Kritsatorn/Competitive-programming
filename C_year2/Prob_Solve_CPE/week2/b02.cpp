#include<stdio.h>
#include<string.h>
char s[110];
int main(int argc, char const *argv[])
{
  /* code */
  scanf("%s",s);
  for(int i=0; i<strlen(s) ;i++) {
    printf("%c",
    s[i] >= 'a' && s[i] <= 'z' ?
    s[i] - 32 : s[i]
    );
  }
  return 0;
}
