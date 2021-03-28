#include <bits/stdc++.h>
using namespace std;

int findMin(const vector<int> &VS, int j)
{
  int maxx = 99999999;
  int idx = -1;
  for (int i = j; i < VS.size(); i++)
  {
    if (VS[i] < maxx)
    {
      maxx = VS[i];
      idx = i;
    }
  }
  return idx;
}

int solve(vector<int> &VS)
{
  int sum = 0;
  for (int i = 0; i < VS.size() - 1; i++)
  {
    int min_idx = findMin(VS, i);
    stack<int> C;
    for (int j = i; j <= min_idx; j++)
      C.push(VS[j]);
    int j = 0;
    while (!C.empty())
      VS[i + j] = C.top(), C.pop(), j++;

    sum += min_idx - i + 1;
  }
  return sum;
}

int main()
{
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++)
  {
    int N;
    cin >> N;
    vector<int> VS(N);
    for (auto &S : VS)
      cin >> S;

    printf("Case #%d: %d\n", i, solve(VS));
    // for (auto &S : VS)
    //   cout << S << " ";
    // cout << "\n";
  }
  return 0;
}
