#include<bits/stdc++.h>
using namespace std ;
struct Bit {
  int a , b ;
}list1[100010] , list2[100010] ;
bool smp(Bit A , Bit B ) {
  if ( A.a == B .a ) return A.b < B.b;
  return A.a < B.a ;
}
main() {

}