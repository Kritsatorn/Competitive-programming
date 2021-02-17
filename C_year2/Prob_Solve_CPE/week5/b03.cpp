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
      sett.push_back(k) , sort(sett.begin() , sett.end());
    if ( m == 2)
      if ( binary_search(sett.begin() ,sett.end() , k) )
        cout << "1" << endl ;
      else
        cout << "0" << endl ;
    if ( m == 3)
      sett.erase(remove( begin(sett), end(sett) , k ) , end(sett));
  }
}