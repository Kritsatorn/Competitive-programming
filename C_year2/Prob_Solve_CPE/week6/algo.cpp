#include<bits/stdc++.h>
using namespace std ;
int arr[20] = {5 , 4 ,3 ,2 ,1 ,6 , 7, 8, 9 ,20} ;
int findNum(int x,int l, int r) {

  if ( l >= r ) return -1;

  int mid = l+r ;   mid /= 2 ;
  printf("%d %d %d \n",l,r,mid);
  if ( x == arr[mid]) return mid ;

  if ( arr[l] > arr[mid]      && ( arr[l] >= x && x > arr[mid]))
      return findNum(x,l,mid)   ;
  else if ( arr[r] > arr[mid] && ( arr[mid] < x && x <= arr[r]) )
      return findNum(x,mid+1,r) ;
  else return -1 ;
}
main() {
  int x;
  x = findNum(11,0,9);
  if( x != -1)
  printf("%d",x);
  else printf("not found");
}