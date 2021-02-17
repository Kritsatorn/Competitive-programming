#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  int current;
  bool check;
  int train[1010];
  stack<int> s;

  while (cin >> n) {
    if (n == 0) break;
    while (cin >> train[0]) {
      if (train[0] == 0) break;
      while (!s.empty()) s.pop();
      current = 1;  check = true;

      for (int i = 1; i < n; i++)
        cin >> train[i];

      for (int i = 0; i < n; i++) {
        if (train[i] == current) {
          current++;  continue;
        } else if (train[i] < current) {
          if (s.size() > 0) {
            if (s.top() == train[i]) {
              s.pop();  continue;
            }
          }
          check = false;
          break;
        } else if (train[i] > current) {
          while (train[i] != current) {
            s.push(current);
            current++;
          }
          current++;
          continue;
        }
      }

      if (check) cout << "Yes" << endl;
      else cout << "No" << endl;
    }

    cout << endl;
  }

  return 0;
}