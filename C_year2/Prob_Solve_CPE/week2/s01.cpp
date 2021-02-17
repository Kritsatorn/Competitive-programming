#include <bits/stdc++.h>
using namespace std;
string s[100010];
string auto_c[100010]];
int n ,ans;

int main(int argc, char const *argv[])
{
  scanf("%d",&n);
  for(int i=0; i<n ;i++) {
    cin >> s[i];
    string temp("");

    for(int j=0 ;j < s[i].length() ;j++) {
      // str cat char
      temp += string(1,s[i][j]);
      for(int h = 0 ; h < i ; h++) {
        size_t pos = 0 ;
        if (temp[0] != s[h][0]) continue;
        if (pos = s[h].find(temp) != string::npos) {
          // printf(" findd %d from %s\n",pos,s[h]) ;
          if ( temp.length() == s[i].length())
            ans += temp.length();
          goto z;
        }
      }
      // cout << "fukc  " +  temp << endl;
      ans += temp.length();
      break;
      z:;
    }
  }
  cout << ans ;
  return 0;
}
