#include<stdio.h>
#include<stdlib.h>
typedef struct CELL *LIST ;
struct CELL {
  int element ;
  LIST next ;
};

int search(int x, LIST L ) {
  while(L != NULL) {
    if ( L -> element == x) return 1;
    L = L -> next ;
  }
  return 0 ;
}

void insert(int x , LIST *pL) {
  LIST  a = new CELL() ;
  a -> element  = x ;
  a -> next     = *pL  ;

}

void Delete(int x , LIST *pL) {
    while(*pL != NULL) {
    if ((*pL) -> next -> element == x) {
      LIST a = (*pL) -> next ;
      (*pL) -> next = (*pL) -> next -> next ;
      free(a) ;
      return ;
    }
    *pL = (*pL) -> next ;
  }
}
int main(int argc, char const *argv[])
{
  /* code */
  return 0;
}
