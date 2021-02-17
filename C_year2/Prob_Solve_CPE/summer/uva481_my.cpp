#include<bits/stdc++.h>
using namespace std;
int MEM[1000000], MEM_id[1000000], P[1000000];
vector<int> vt ;
stack<int > ANS ;
void print(int end) {
    if(end < 0) return;
    print(P[end]);
    printf("%d\n", vt[end]);
}
main() {
  int num , count = -1 , R = 0 , L = 0 ;

  while(cin >> num ) {
    count ++;
    vt.push_back(num) ;
    int pos = lower_bound(MEM, MEM+R ,num) - MEM ;
    MEM[pos] = num ;
    MEM_id[pos] = count ;
    P[count] = pos > 0 ? MEM_id[pos-1] : -1 ;
    if( pos == R) R++ , L = count ;
  }
  printf("%d\n-\n", R);
  while(L >= 0 )ANS.push(vt[L]), L = P[L] ;
  while( !ANS.empty() ) printf("%d\n",ANS.top()) , ANS.pop();

}