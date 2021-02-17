#include<bits/stdc++.h>
using namespace std ;
main() {
  int test_case ,count_case = 0;
  scanf("%d",&test_case);
  while (count_case++ < test_case ) {
    int arr[110][110] ;
    int n ,sum=0 ,row_rep = 0 , column_rep = 0;
    bool column_check[110][110], row_check[110] ,ever_column[110];
    memset(column_check, false, sizeof(column_check));
    memset(ever_column, false, sizeof(ever_column));
    scanf("%d",&n);
    for(int i=1 ; i<=n ; i++) {
      memset(row_check, false, sizeof(row_check));
      bool ever = false ;
      for(int j=1 ; j<=n ; j ++) {
        scanf("%d",&arr[i][j]);
        if ( i == j ) sum += arr[i][j] ;
        int x = arr[i][j] ;
        /// row
        if ( !row_check[x] ) row_check[x] = true ;
        else if ( row_check[x] )
          if ( !ever ){
            row_rep += 1 ;
            ever = true ;
          }
        /// column
        if ( !column_check[j][x] ) column_check[j][x] = true ;
        else if ( !ever_column[j] ) {
          column_rep += 1 ;
          ever_column[j] = true ;
        }

      }
    }

    printf("Case #%d: %d %d %d\n",count_case,sum,row_rep,column_rep);

  }
}