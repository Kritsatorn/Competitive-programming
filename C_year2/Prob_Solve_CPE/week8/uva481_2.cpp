#include<bits/stdc++.h>
using namespace std;
void FindLIS(vector<int> vt , int N) {
  vector<int> lis , root(N) ;
  int L ,R ;
  lis.push_back(0);

  for(int n=1 ; n<N ; n++) {
  // incresing
    if ( vt[lis.back()]  < vt[n] ) {
      root[n] = lis.back() ;
      lis.push_back(n) ;
      continue ;
    }
  // Bi - search
    for( L=0 , R = lis.size() - 1 ; L < R ; ) {
      int mid  = ( L + R ) / 2 ;
      if ( vt[lis[mid]] < vt[n] )   L = mid + 1 ;
      else R = mid ;
    }
  // update
    if ( vt[n] < vt[lis[L]] ) {
      if ( L > 0 ) root[n] = lis[ L-1 ] ;
      lis[L] = n ;
    }
  }

  for ( L = lis.size() , R = lis.back() ; L-- ; R = root[R] ) lis[L] = R ;

  cout << lis.size() << endl << "-" << endl ;
  for(int x : lis)
    cout << vt[x] << endl ;
}
main() {
  vector<int> vt ;
  int n ;
  while( cin >> n ) vt.push_back(n);

  if ( !vt.empty ())
    FindLIS(vt,vt.size());
  else printf("0\n-\n");
}