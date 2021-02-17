#include<bits/stdc++.h>
using namespace std ;
int n,m ;
int arr[200020] , mem[200020] ;
// int bi_search(int x) {
//   int l , r , m;
//   l = 0 ; r = n-1;
//   while( l <= r ) {

//     m = (l + (r ) )/2 ;
//     printf("%d %d %d\n",m,l,r);
//     if ( mem[m] == x) return m ;
//     if ( mem[m] > x ) r = m +1;
//     else l = m -1 ;
//   }
//   return m ;
// }
int fuck ;
int binarySearch(int arr[], int l, int r, int x) 
{ 
  int mid ;
    if (r >= l) { 
        mid = l + (r - l) / 2; 
        fuck = mid ;
    // printf("%d %d %d\n",l,r,mid);
        // If the element is present at the middle 
        // itself 
        if (arr[mid] == x) 
            return mid; 
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (arr[mid] <= x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return binarySearch(arr, mid + 1, r, x); 
    } 
  
    // We reach here when element is not 
    // present in array 
    return mid; 
} 
main() {
  scanf("%d %d",&n,&m);
  int minn = INT_MAX ; int maxx = 0 ;
  for(int i=0 ; i<n ; i++) {
    scanf("%d",&arr[i]);
    minn = min(minn,arr[i]);
    // maxx = max(maxx,arr[i]);
    mem[i] = minn ;
  }
  // printf("%d \n",binarySearch(mem,0,n-1,120));
  // printf("%d",fuck );
  int l , k ;
  for(int i=0 ; i<m;i++) {
    scanf("%d %d",&l,&k);
    switch (l)
    {
    case 1:
      printf("%d\n",mem[k-1]);
      break;
    case 2:
      binarySearch(mem,0,n-1,k);
      if ( k > mem[0] ) printf("0\n");
      else if ( k <= minn) printf("%d \n",n);
      else {
        while(fuck+1 < n ) {
            if ( k <= mem[fuck+1])fuck++;
            else break;
        }
        printf("%d\n",fuck+1);
      }
      break;
    }
  }
}