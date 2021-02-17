#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
int n;
int main(int argc, char const *argv[])
{
  scanf("%d",&n);
  for(int j=0 ;j <n ;j++ ) {
    char s[30];
    scanf("%s",s);
    stack<char> st;
    for(int i=0; i< strlen(s) ;i++) {
      if( !st.empty() )
        if(st.top() + 2 == s[i] || st.top() + 1 == s[i])
          st.pop();
        else
          st.push(s[i]);
      else
        st.push(s[i]);
      // printf("%c %d\n",st.top(),st.size());
    }
    printf("%s\n", st.empty() ? "yes" : "no");

  }
  return 0;
}
