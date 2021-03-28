#include <bits/stdc++.h>
using namespace std;
long long int solve()
{
  string S;
  int X, Y;
  cin >> X >> Y >> S;

  int val[100][100];

  val['C']['J'] = X;
  val['J']['C'] = Y;

  long long int sum = 0;
  int cnt = 0;
  for (int i = 1; i < S.length(); i++)
  {
    char C = S[i];
    if (C == '?')
      cnt++;
    if (C == 'C' || C == 'J')
    {
      // back
      char bef = S[i - 1];
      if (bef == '?')
      {
        if (i - cnt - 1 < 0)
        {
          cnt = 0;
          continue;
        }
        bef = S[i - cnt - 1];
        cnt = 0;
      }

      if (bef == C)
        continue;
      sum += val[bef][C];
    }
    // printf(" %c at %d  =  %d \n", C, i, sum);
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
    printf("Case #%d: %ld\n", i, solve());
  }
  return 0;
}
