#include<bits/stdc++.h>
using namespace std ;
int n ,arr[100010];
long long int count_pair ;
void mergeSort(int h,int t) {
  // printf("%d %d\n",h,t);
  if ( h >= t) return ;
  if ( t - h == 1)
    if ( arr[t] < arr[h]) {
      int temp = arr[t] ;
      arr[t] = arr[h] ; arr[h] = temp ;
      count_pair ++ ;
      return ;
    }
    else return ;

  int mid = h + ( t - h ) /2 ;
  mergeSort(h,mid) ;
  mergeSort(mid+1,t) ;
  vector<int> tmp ;
  int idx1 = h , idx2 = mid+1; long long  int count_across = 0;
  while( ( idx1 <= mid ) && ( idx2 <= t ) ) {
    if ( arr[idx1] <= arr[idx2] ) {
      tmp.push_back(arr[idx1++]) ;
      // count_pair   += count_across ;
    }
    else {
      tmp.push_back(arr[idx2++]) ;  count_pair += mid - idx1 + 1;
      // count_across ++ ;
    }
  }
  while(idx1 <= mid)tmp.push_back(arr[idx1++]) ;
  while(idx2 <= t)tmp.push_back(arr[idx2++]) ;
  int k = 0 ;
  for(int i= h ; i <= t ; i++) arr[i] = tmp[k++] ;
  return ;
}
main() {
  scanf("%d",&n) ;
  for(int i=0 ; i<n ; i++) scanf("%d",&arr[i]);
  count_pair = 0 ;
  mergeSort(0,n-1) ;
  // for(int i=0 ; i<n ; i++) printf("%d ",arr[i]);
  printf("%lli",count_pair);

}