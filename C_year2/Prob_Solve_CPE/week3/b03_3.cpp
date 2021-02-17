#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
struct List {
  std::string data ;
  struct List *next ;
};
struct List *head_platform[100010] ,*end_platform[100010];
main(){
  int n = 0;
  scanf("%d",&n);
  while(n-- > 0) {
    int num, brok ;
    char c;
    scanf(" %c %d %d",&c,&num,&brok);
    switch (c) {
    case 'N' :
      struct List *train ;
      train = (struct List *)malloc(sizeof(struct List)) ;
      train -> data = std::to_string(num);
      train ->next = NULL ;

      if(head_platform[brok] == NULL) {
        head_platform[brok] = train ;
        end_platform[brok] = train ;
      } else {
        end_platform[brok] -> next = train ;
        end_platform[brok] = train ;
      }

      break;

    case 'M' :
      if(head_platform[brok] == NULL) {
        head_platform[brok] = head_platform[num];
        end_platform[brok] = end_platform[num];
      } else {
        end_platform[brok] -> next = head_platform[num] ;
        end_platform[brok] = end_platform[num];
      }
      head_platform[num] = NULL ;
      end_platform[num] = NULL ;
      break;
    };
  }
  for(int i=1 ; i<=100000;i++)
  while(head_platform[i] != NULL) {
    std::cout << head_platform[i] -> data << '\n';
    head_platform[i] = head_platform[i] -> next;
  }
}