#include <bits/stdc++.h>
using namespace std;

void solve(int t)
{
  int n;
  cin >> n;
  string everything;
  vector<string> prefs;
  vector<string> suffs;
  for (int _ = 0; _ < n; _++)
  {
    string s;
    cin >> s;
    for (char a : s)
      if (a != '*')
        everything += a;
    string g = s + "*";
    for (int i = 0;; i++)
    {
      if (g[i] == '*')
      {
        prefs.push_back(g.substr(0, i));
        break;
      }
    }
    g = "*" + s;
    for (int i = 0;; i++)
    {
      if (g[(int)g.size() - 1 - i] == '*')
      {
        suffs.push_back(g.substr((int)g.size() - i));
        break;
      }
    }
  }
  string bp = "";
  string bs = "";
  for (int i = 0; i < n; i++)
  {
    if (prefs[i].size() > bp.size())
      bp = prefs[i];
    if (suffs[i].size() > bs.size())
      bs = suffs[i];
  }
  string ret = bp + everything + bs;
  bool works = true;
  for (string g : prefs)
  {
    if (g.size() > ret.size() || ret.substr(0, g.size()) != g)
      works = false;
  }
  for (string g : suffs)
  {
    if (g.size() > ret.size() || ret.substr(ret.size() - g.size()) != g)
      works = false;
  }
  if (!works)
    ret = "*";
  cout << "Case #" << t << ": " << ret << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++)
  {
    solve(t);
    cout << flush;
  }
}