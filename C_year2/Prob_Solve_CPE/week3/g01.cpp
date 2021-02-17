#include<stdio.h>
#include<queue>
using namespace std;
struct List {
  int data ;
  struct List *next,*prev ;
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
  char c;
  struct List point ;
  queue<int> q;
  point = list[1];
  for(int i=0 ; i<m ;i++) {
    int tmp;
    scanf(" %c",&c);
    switch(c) {
      case 'F' : if (point.next != NULL)
      point = *point.next;
      q.push(point.data);
      break ;

      case 'B' : if (point.prev != NULL)
      point = *point.prev;
      q.push(point.data);
      break ;

      case 'C' : scanf("%d",&tmp);
      // is tail ?
      if (list[tmp].next == NULL ) {
        struct List *tmp_list, tmp_point ;
        tmp_point = *(&list[tmp]);
        while(true) {
         // printf("bef %d %d %d\n ",tmp_point.data,tmp_point.next,tmp_point.prev);
          tmp_list = tmp_point.next ;
          tmp_point.next = tmp_point.prev ;
          tmp_point.prev = tmp_list ;
         // printf("af %d %d %d\n ",tmp_point.data,tmp_point.next,tmp_point.prev);
          if(tmp_point.next == NULL)
          break;
          tmp_point = *tmp_point.next;
        }
      }
      // add
      if (point.next != NULL)
          (*point.next).prev = NULL;
        point.next = &list[tmp] ;
        list[tmp].prev = &point;
      //answer
      point = *point.next;
      q.push(point.data);
      break ;
    }
  }
///answer
  while( !q.empty() ) {
    printf("%d \n",q.front());
    q.pop();
  }
  return 0;
}
