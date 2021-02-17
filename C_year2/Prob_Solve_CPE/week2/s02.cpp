#include <bits/stdc++.h>
using namespace std;
string a,b ;
stack<int> st;
int main(int argc, char const *argv[])
{
  cin >> a ;
  cin >> b ;
  int a_length = a.length() , b_length = b.length() ;
  int maxx = max(a_length,b_length);
  int tot = 0;
  for(int i = 1 ; i <= maxx ; i++ ) {
    int cal = ( i <= a_length ? a[ a_length - i] - '0' : 0 )
    + ( i <= b_length ? b[ b_length - i] - '0' : 0 )  ;
    //printf("%d %d\n",a[ a_length - i] - '0',b[ b_length - i] - '0');

    st.push( (cal+tot) % 10);
    tot = cal+tot >= 10 ? 1: 0;
  }
  if (tot) st.push(tot);
  while( !st.empty())
    cout << st.top() , st.pop();
  return 0;
}
