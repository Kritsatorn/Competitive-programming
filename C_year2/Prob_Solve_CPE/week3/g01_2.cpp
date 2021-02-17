#include<stdio.h>
#include<queue>
using namespace std;
struct List {
  int data ;
  struct List *next,*prev ;
  bool operator==(const List& a) const{
      return data == a.data;
    }
};
struct List list[100010];
bool check[100010];

void checkInput(int count) {
// check input
  struct List tmp ;
  for(int i=1 ;i<=count ; i++) {
    if (check[i]) continue;
    tmp.next = &list[i];
    do {
      tmp = *tmp.next;
      check[tmp.data] = 1;
      printf("%d ",tmp.data);
    } while(tmp.next != NULL) ;
    printf("\n");
  }
  return ;
}

int main(int argc, char const *argv[])
{
  // initial list
  list[1].prev = NULL;
  list[1].data = 1;
  for(int i=2 ; i <=100000 ; i++) {
    list[i].data = i;
    list[i-1].next = &list[i];
    list[i].prev = &list[i-1];
  }
  list[100000].next = NULL;

  // input
  int n ,m ,count =0;
  scanf("%d %d",&n,&m);
  for(int i=0 ; i<n ; i++) {
    int tmp ;
    scanf("%d",&tmp);
    count += tmp ;
    list[count].next = NULL ;
    list[count+1].prev = NULL ;
  }
 //checkInput(count);

// do
  char c;
  struct List *point ,*point_prev ,*point_next , *tmp;
  queue<int> q;
  point = &list[1];
  point_prev = list[1].prev ;
  point_next = list[1].next ;
  for(int i=0 ; i<m ;i++) {
    int num;
    scanf(" %c",&c);
// move algo
    switch(c) {
      case 'F' :
        if( point_next != NULL) {
          point_prev = point ;
          tmp = point_next ;
          point_next = point_next -> prev == point ?
            point_next -> next : point_next -> prev ;
          point = tmp ;
        }
        q.push( point-> data );
      break ;

      case 'B' :
        if( point_prev != NULL) {
            point_next = point ;
            tmp = point_prev ;
            point_prev = point_prev -> next == point ?
              point_prev -> prev : point_prev -> next ;
            point = tmp ;
          }
          q.push( point-> data );
      break ;

      case 'C' : scanf("%d",&num);
        // cut off
        if (point_next == NULL) goto a;
        point_next -> prev = point_next -> prev == point ?
          NULL : point_next -> prev ;
        point_next -> next = point_next -> next == point ?
          NULL : point_next -> next ;
        // regular
        a: ;
        // add new
        if ( point -> prev == point_prev)
          point -> next = &list[num] ;
        else
          point -> prev = &list[num] ;
        //--
        point_prev = point ;
        point = &list[num];
        // new to old
        if ( point -> next == NULL) {
          point_next = point -> prev ;
          point -> next = point_prev ;
        } else {
          point_next = point -> next ;
          point -> prev = point_prev ;
        }
        //---
        q.push( point-> data );
      break ;
    }
// end move
  }
///answer
  while( !q.empty() ) {
    printf("%d \n",q.front());
    q.pop();
  }
  return 0;
}

