#include<stdio.h>
struct List {
  // int data ;
  struct List *next,*prev ;
};
int main(int argc, char const *argv[])
{
  int n ;
  scanf("%d",&n);
  struct List list[n+1];
  // printf("%d\n%d",&list[0],&list[1]);
  for(int i=1 ; i<=n ; i++) {
    list[i].next = nullptr;
    list[i].prev = nullptr;
  }
  // printf("test %d %d %d\n",&list[0],&list[1],&list[1] - &list[0]);
  for(int i=1 ; i<n ; i++) {
    int bead , to ;
    scanf("%d %d",&bead,&to);

    list[bead].prev = &list[to];

    if ( list[to].next != nullptr ) {
      struct List *tmp = &list[bead];
      while(tmp->next != nullptr)
        tmp = tmp -> next;
      tmp -> next =  list[to].next;
      list[to].next -> prev = tmp ;
      list[to].next = &list[bead];
      // printf("pussy\n");
      // printf("%d",tmp->next - &list[0]);
    }
    else
      list[to].next = &list[bead];
      // printf("%d bead %d =  %d %d\n",i,bead,list[to].next- &list[0],list[bead].prev - &list[0]);
  }

  for(int i=1 ; i<=n ; i++) {
    if ( list[i].prev == nullptr) {
      struct List tmp = list[i];
      printf("%d ",i);
      while(tmp.next != nullptr) {
        printf("%d ",tmp.next - &list[0] );
        tmp = *tmp.next;
      }
      break;
    }
  }
  return 0;
}
