#include<stdio.h>
#include<stdlib.h>
struct List {
  long int data ;
  struct List *next ;
};
struct List *head_platform[100010] ,*end_platform[100010], *p_head;
main(){
  int n = 0;
  scanf("%d",&n);
  while(n-- > 0) {
    int brok ;
    long int num;
    char c;
    scanf(" %c %li %d",&c,&num,&brok);
    switch (c) {
    case 'N' :
      struct List *train ;
      train = (struct List *)malloc(sizeof(struct List)) ;
      train -> data = num ;
      train ->next = NULL ;
      // insert
      if(head_platform[brok] == NULL) {
        head_platform[brok] = train ;
        end_platform[brok] = train ;
      } else {
        end_platform[brok] -> next = train ;
        end_platform[brok] = train ;
      }

      break;

    case 'M' :
      if (head_platform[num] == NULL) continue;
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
   printf("every line \n");
    for(int i=1 ; i<=100000;i++)
    p_head = head_platform[i] ;
    if(p_head == NULL) printf("fuck");
    while(p_head != NULL) {
      printf("%li ",p_head -> data);
      p_head = p_head -> next;
    }
  }
  for(int i=1 ; i<=100000;i++)
  while(head_platform[i] != NULL) {
    printf("%li \n",head_platform[i] -> data);
    head_platform[i] = head_platform[i] -> next;
  }
}