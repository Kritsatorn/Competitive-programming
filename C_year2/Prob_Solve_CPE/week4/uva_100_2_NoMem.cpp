#include<iostream>
using namespace std;
// int mem[1000010] ;
int  cal (int n ) {
  // printf("%d ",n);
  // if ( mem[n] != 0 ) return mem[n] ;
  if ( n == 1 ) return 1 ;
  if ( n % 2 == 1 ) return 1 + cal(3*n + 1) ;
  else return 1 + cal( n / 2 ) ;
}
int main() {
  int a , b ;
  while ( cin >> a >> b ) {
    int m = 0 ;
    for(int i = min(a,b) ; i <= max(a,b) ; i++ ) m = max(m , cal(i)) ;
    cout << a << " " << b << " " << m << endl;
  }
  return 0;
}