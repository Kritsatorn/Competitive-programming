#include<bits/stdc++.h>
using namespace std ;
int N ,x[100] ,s[100] ;
int mem[100][100];
int Mic(int day, int day_s) {
  if ( day > N) return 0 ;
  if ( mem[day][day_s]!=0) return mem[day][day_s] ;
  return mem[day][day_s] = max (
    (x[day] >= s[day_s] ? s[day_s] : x[day]) + Mic(day+1 , day_s+1) ,
    0 + Mic(day+1 , 1 )
  ) ;
}
main() {

  cin >> N ;
  for(int n=1 ; n <= N ; n++) cin >> x[n] ;
  for(int n=1 ; n <= N ; n++) cin >> s[n] ;
  int ANS ;
  ANS = Mic(1,1);
  // for(int i=1 ; i<=N ; i++)
  // for(int j=1 ; j <=N ; j++)
  //  cout << "mem " << mem[i][j] << endl ;
  cout << ANS << endl ;
}