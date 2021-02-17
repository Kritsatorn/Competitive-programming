#include<bits/stdc++.h>
using namespace std ;
bool comp(int a, int b) 
{ 
    return (a < b); 
} 

main() {
  int arr[10] = {12,3,4} ;
  int A = -8 ;
  printf("%d",min({1,A,3},comp));
}