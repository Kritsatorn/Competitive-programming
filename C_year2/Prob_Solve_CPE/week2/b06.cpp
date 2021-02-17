#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
  string s;
  string delimeter = "_" ;
  size_t pos = 0;
  string token ;
  cin >> s ;
  stack<string> st;
  while ( (pos = s.find(delimeter)) != string::npos ) {
      // cout << pos <<endl; ;
    token = s.substr(0,pos);
    st.push(token);
    // reverse(token.begin(), token.end());
    // cout << token << delimeter ;
    s.erase(0 , pos + delimeter.length() );
  }
  // reverse(s.begin(), s.end()) ;
  // cout << s ;
  st.push(s);
  while ( st.size() != 1 )  {
    cout << st.top() << delimeter ;
    st.pop();
  }
  cout << st.top() ;
  st.pop();
  return 0;
}
