#include<bits/stdc++.h>
using namespace std ;
struct Node {
  int data ;
  struct Node *left ,*right ;
} ;

struct Node* create(int num) {
  struct Node *tmp ;
  tmp = new Node ;
  tmp -> data = num;
  tmp -> left = NULL;   tmp -> right = NULL ;
  return tmp ;
}
void Insert(struct Node *ptr , int num) {
  if (  num > ptr -> data  )
    if ( ptr -> right == NULL ) ptr -> right = create(num);
    else return Insert(ptr -> right , num);

  if (  num < ptr -> data  )
    if ( ptr -> left == NULL) ptr -> left = create(num) ;
    else return Insert(ptr -> left  , num);
  return ;
}
bool find(struct Node *ptr ,int num) {
  if ( ptr == NULL) return false ;

  if ( num > ptr -> data) return find(ptr -> right ,num);
  if ( num < ptr -> data) return find(ptr -> left  ,num);
  if ( num == ptr -> data)
    return true ;
}
void print( struct Node *ptr ,int level) {
  if ( ptr  == NULL) return ;
  print( ptr -> right, level +1);
  for(int i = 0 ; i < level ; i ++)printf("*** ");
  printf("%d \n", ptr -> data);
  print( ptr -> left , level +1);
  return ;
}
struct Node* minVal(struct Node *ptr) {
  struct Node* tmp = ptr;
  while( tmp && tmp -> left != NULL)
    tmp = tmp -> left;
  return tmp ;
}
struct Node*  del(struct Node *ptr ,int num) {
  //base
  if ( ptr == NULL ) return ptr;

  if ( num > ptr -> data ) ptr -> right =  del( ptr -> right, num) ;
  if ( num < ptr -> data ) ptr -> left =   del( ptr -> left , num) ;
  if ( ptr -> data == num) {
    //leaf
    struct Node *tmp ;
    if ( ptr -> left == NULL && ptr -> right == NULL) return NULL ;
    // one child
    if ( ptr -> left == NULL && ptr -> right != NULL) {
      tmp = ptr -> right ;  free(ptr) ;
      return tmp ;
    }
    if ( ptr -> right == NULL && ptr -> left != NULL) {
      tmp = ptr -> left ;  free(ptr) ;
      return tmp ;
    }
    // two child
    tmp = minVal(ptr -> right) ;
    ptr -> data = tmp -> data ;
    ptr -> right = del(ptr -> right,tmp -> data);
  }
  return ptr;
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
        if ( root == NULL) {
          root = new Node ;
          root -> left = NULL ;   root -> right = NULL ;
          root -> data = num  ;
        }
        else Insert(root,num ) ;
        break;

      case 2 :
        if ( root == NULL) k = 0 ;
        else k = find(root , num);
        printf("%d\n",k);
        break ;

      case 3:
        root = del(root , num);
        break ;
    }
  }
  // printf("%d \n", root -> data);
  // print(root,0);
}