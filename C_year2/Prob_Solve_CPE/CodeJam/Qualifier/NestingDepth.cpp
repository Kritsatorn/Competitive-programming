#include<bits/stdc++.h>
using namespace std ;
main() {
  int test_case ,count_case = 0;
  scanf("%d",&test_case);
  while (count_case++ < test_case ) {
    int n ,x ;
    char arr[110] ;
    queue<char> q ;  int current_st = 0 ;
    scanf("%s",arr);
    for(int i=0 ; i< strlen(arr) ; i++) {
      x =  arr[i] - '0' ;
      // printf("x : %d\n",x);
      while( current_st <  x) q.push('('), current_st++ ;
      while( current_st >  x) q.push(')'),current_st-- ;
      q.push( arr[i]) ;
    }
    x = 0 ;
    while( current_st >  x) q.push(')'),current_st-- ;
    printf("Case #%d: ",count_case);
    for( ;!q.empty();q.pop() )printf("%c",q.front());
    printf("\n");
  }
}