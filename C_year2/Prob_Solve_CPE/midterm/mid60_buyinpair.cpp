#include<bits/stdc++.h>
using namespace std;
int n , l , r ;
int arr[200010] ;
main() {
  cin >> n >> l >> r ;
  for(int i=0 ; i<n; i++)
  scanf("%d",&arr[i]);

  sort(arr , arr+n );
  for(int i=0 ; i<n; i++) {
    printf("%d ",arr[i]);
  }

}