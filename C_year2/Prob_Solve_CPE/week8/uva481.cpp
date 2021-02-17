#include<bits/stdc++.h>
using namespace std;
int mem_size[1000000];
void FindLIS(vector<int> vt , int N) {
  vector<int> mem[N+1] ;
  int max_size = 0 , max_idx ;
  for(int n=0 ; n<N ; n++) {
    for(int b=n - 1; b>=0 ; b--) {
      if (
        vt[n] > vt[b] &&
        // mem[b].size()  + 1 > mem[n].size()
        mem_size[b] + 1 > mem_size[n]
      ) mem[n] = mem[b] , mem_size[n] = mem_size[b];
    }
    mem[n].push_back(vt[n]);
    mem_size[n] += 1 ;
    if ( mem[n].size() > max_size )
      max_size = mem[n].size() ,max_idx = n ;
  }
  cout << max_size << endl << "-" << endl ;
  for(int i=0 ; i < mem[max_idx].size() ; i++)
    cout << mem[max_idx][i] << endl ;
}
main() {
  vector<int> vt ;
  int n ;
  while( cin >> n) vt.push_back(n);
  memset(mem_size, 1 , sizeof(mem_size));
  if ( !vt.empty ())
    FindLIS(vt,vt.size());
  else printf("0\n-\n");
}