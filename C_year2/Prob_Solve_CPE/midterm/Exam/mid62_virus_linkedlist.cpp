#include<bits/stdc++.h>
using namespace std;
struct List {
  long int data ;
  struct List *next ,*prev ;
};
struct List *head, *tail, *virus ;
int n ,m;
main() {
  scanf("%d %d",&n,&m);
  int num ;
  for(int i=0 ; i < n ; i++ ){
    scanf("%d",&num);
      struct List *dna ;
      dna = (struct List *)malloc(sizeof(struct List)) ;
      dna -> data = num ;
      dna ->next = NULL ; dna -> prev = NULL ;

      if ( head == NULL) {
        head = dna ; tail = dna ; virus = dna ;
      }
      else {
        tail -> next = dna ;
        (tail -> next) -> prev = tail ;
        tail = dna ;
      }
  }
    char c; int k ;
   for(int i=0 ; i < m ;i++) {
    scanf(" %c",&c);
    struct List *dna , *print;
    switch (c)
    {
      case '1': virus = head;
        break;
      case '2': if ( virus -> next != NULL) virus = virus -> next ;
        else virus = head ;
        break;
      case '3':
        scanf("%d",&k);
        dna = (struct List *)malloc(sizeof(struct List)) ;
        dna -> data = k ;
        dna ->next = NULL ; dna -> prev = NULL ;
        if ( virus -> prev != NULL ) {
          (virus -> prev) -> next = dna ;
          dna -> prev = virus -> prev ;
          dna -> next = virus ;
          virus -> prev = dna ;
        }
        else {
          dna -> next = virus ; virus -> prev = dna;
          head = dna ;
        }
        break;
      case '4':
        scanf("%d",&k);
        dna = (struct List *)malloc(sizeof(struct List)) ;
        dna -> data = k ;
        dna -> next = NULL ; dna -> prev = NULL ;
        if ( virus -> next != NULL) {
          (virus -> next) -> prev = dna ;
          dna -> next = virus -> next ;
          virus -> next = dna ;
          dna -> prev = virus ;
        }
        else {
          virus -> next = dna ; dna -> prev = virus ;
          tail = dna ;
        }
        break;
      }
    // print = head ;
    // while( print != NULL) {
    //   printf("%d ",print -> data);
    //   print = print -> next ;
    // }
    // printf(" v : %d",virus -> data);
    // printf("\n");
  }

    struct List *print = head ;
    while( print != NULL) {
      printf("%d \n",print -> data);
      print = print -> next ;
    }
}