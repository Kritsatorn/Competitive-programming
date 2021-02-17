#include <bits/stdc++.h>
using namespace std;
main() {
  int n;
  vector<int> sett ;
  cin >> n ;
  for(int i=0 ; i<n ; i++ ) {
    int m ,k ;
    scanf("%d %d",&m,&k);
    if ( m == 1 )
      sett.push_back(k),sort(sett.begin() , sett.end());
    if ( m == 2) {
      if( sett.empty() ) cout << 0 << endl ;
      else {
        int index = lower_bound( sett.begin() , sett.end() , k) - sett.begin() ;
        printf("%d\n",sett.size() - index + ( sett[index] == k ? -1 : 0));
      }

    }

  }
}