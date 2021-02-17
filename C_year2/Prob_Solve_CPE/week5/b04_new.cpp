#include<bits/stdc++.h>
using namespace std ;
struct Node {
  int data , more ;
  struct Node *left ,*right ;
} ;

struct Node* create(int num) {
  struct Node *tmp ;
  tmp = new Node ;
  tmp -> data   = num   ;   tmp -> more   = 0     ;
  tmp -> left   = NULL  ;   tmp -> right  = NULL  ;
  return tmp ;
}
void Insert(struct Node *ptr , int num) {
  if (  num > ptr -> data  ) {
     ptr -> more += 1 ;
    if ( ptr -> right == NULL ) ptr -> right = create(num);
    else
      return  Insert(ptr -> right , num);
  }
  if (  num < ptr -> data  )
    if ( ptr -> left == NULL) ptr -> left = create(num) ;
    else return Insert(ptr -> left  , num);
  return ;
}
int findMore(struct Node *ptr ,int num) {
  if ( ptr == NULL) return 0 ;

  if ( num < ptr -> data) return 1 +  ptr -> more + findMore(ptr -> left  ,num);
  else if ( num > ptr -> data ) return findMore(ptr -> right, num );
  return ptr -> more ;
}
main() {
  int n;
  struct Node *root ;
  root = NULL ;
  scanf("%d",&n);
  int opt ,num ;
  for(int i=0 ; i <n ; i++) {
    scanf("%d %d",&opt,&num);
    int k;
    switch (opt)
    {
      case 1:
        if ( root == NULL) root = create(num);
        else Insert(root,num ) ;
        break;

      case 2 :
        if ( root == NULL) k = 0 ;
        else k = findMore(root , num);
        printf("%d\n",k);
        break ;

    }
  }
  // printf("%d \n", root -> more);
  // print(root,0);
}