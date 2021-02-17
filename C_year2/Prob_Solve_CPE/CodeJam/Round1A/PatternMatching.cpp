#include<bits/stdc++.h>
using namespace std ;
struct List {
  char c ;
  struct List *next ;
};
void printL(List *print) {
  for(;print != nullptr;print = print ->next)
    printf("%c ",print ->c) ;
  return ;
}
main() {
  int test_case ,count_case = 0;
  scanf("%d",&test_case);
  while (count_case++ < test_case ) {

    int n;
    char s[52][110] ;
    // struct List *initial ;
    // initial = (struct List *)malloc(sizeof(struct List)) ;
    // initial -> c = '*' ;
    // initial ->next = NULL ;
    // phead = initial ;

    scanf("%d",&n);
    for(int i=0 ; i <n ; i++)
      scanf("%s",s[i]);

    List *current = nullptr ,*phead = nullptr;
    for(int i=0 ; i < strlen(s[0]) ; i++) {
      struct List *tmp ;
      tmp  = (struct List *)malloc(sizeof(struct List)) ;
      tmp  -> c = s[0][i] ;
      tmp  ->next = NULL ;

      if ( phead == nullptr) phead = tmp ;
      if ( current == nullptr) current = tmp ;
      else current -> next = tmp , current = current -> next ;
      // printf("%c %c \n",current ->c,s[0][i]);
    }
    // printL(phead);

    for(int i=1 ; i < n ; i ++) {
      List *current ;
      current = phead ;
      for(int j=0 ; j < strlen(s[i]); j ++ , current = current -> next){
        if ( s[i][j] == current -> c) continue ;
        if ( current -> c == '*') {
          List *insteadStar = nullptr ;
          char End ;
          if ( current -> next != nullptr)
            End = (current -> next) ->c ;
          else End = 0 ;

          while(true) {
            if ( s[i][j] == '*') break ;
            if ( s[i][j] == End) {j-- ;break ;}
            struct List *tmp ;
            tmp  = (struct List *)malloc(sizeof(struct List)) ;
            tmp  -> c = s[i][j] ;
            tmp  ->next = NULL ;

            if ( insteadStar == nullptr)insteadStar = tmp ;
            else 
          }

        }

      }
    }

    // ----
  }
}