#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
  string s;
  string delimeter = "_" ;
  size_t pos = 0;
  string token ;
  cin >> s ;
  while ( (pos = s.find(delimeter)) != string::npos ) {
    token = s.substr(0,pos);
    reverse(token.begin(), token.end());
    cout << token << delimeter ;
    s.erase(0 , pos + delimeter.length() );
  }
  reverse(s.begin(), s.end()) ;
  cout << s ;
  return 0;
}
