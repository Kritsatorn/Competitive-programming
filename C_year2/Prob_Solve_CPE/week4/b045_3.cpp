#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>>> p;
main() {
  int n, a, b;
  scanf("%d",&n);
  for(int i=0 ; i <n; i++) {
    scanf("%d %d",&a,&b);
    p.push( make_pair(b,a) );
  }
  int count = 0;
  auto it = p.top();  p.pop() ;
	int start = it.second;
	int end = it.first;
  count ++ ;
  while( !p.empty() ) {
    auto itr = p.top(); p.pop();
    if ( itr.second >= end ) {
      start = itr.second;
      end = itr.first;
      count ++;
    }
  }
  printf("%d",count);
}