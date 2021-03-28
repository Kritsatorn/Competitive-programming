#include <bits/stdc++.h>
using namespace std;
string solve(int N, int C)
{
  // int N, C;
  // cin >> N >> C;
  vector<int> VI;

  int sum = 0;
  for (int i = 0; i < N; i++)
  {
    VI.push_back(i + 1);
    sum += N - i;
  }
  if (C < N - 1 || C > sum)
  {
    // cout << "IMPOSSIBLE"
    //      << "\n";
    return "IMPOSSIBLE";
  }

  for (int i = 0; i < N; i++)
  {
    // j - i + 1 == N -1 -i + 1
    int min_idx;
    if (C > N - i)
      min_idx = N - i, C -= N - i;
    else
      min_idx = C + i;
    min_idx -= 1;
    // printf("min : %d at %d\n", min_idx, i);
    if (min_idx >= N)
    {
      // cout << "IMPOSSIBLE"
      //      << "\n";
      return "IMPOSSIBLE";
    }
    stack<int> st;
    for (int j = i; j <= min_idx; j++)
      st.push(VI[j]);
    int j = 0;
    while (!st.empty())
      VI[i + j] = st.top(), st.pop(), j++;
  }

  if (C > 0)
  {
    // cout << "IMPOSSIBLE"
    //      << "\n";
    return "IMPOSSIBLE";
  }
  stringstream ss;
  for (size_t i = 0; i < VI.size(); ++i)
  {
    if (i != 0)
      ss << " ";
    ss << VI[i];
  }
  // string s = ss.str();
  // cout << ss.str() << "\n";
  return ss.str();
}

int main()
{
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++)
  {
    int N, C;
    cin >> N >> C;
    // printf("Case #%d: ", i);
    cout << "Case #" << i << " " << solve(N, C) << "\n";
  }
  return 0;
}
