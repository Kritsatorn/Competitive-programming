#include<bits/stdc++.h>
using namespace std ;

class BST {
  int data ;
  BST *left, *right ;
  public :
  BST();
  BST(int);
  BST* Insert(BST *, int );
  BST* Search(BST* , int );
  BST* Delete(BST* , int );
  BST* Min(BST*);
  void Inorder(BST *,int );
};
// default
BST :: BST() : data(0), left(NULL), right(NULL){}
// new
BST :: BST(int val) {
  data = val ;
  left = right = NULL ;
}
// Insert
BST* BST:: Insert(BST *root, int val) {
  // if root is NULL
  if ( !root )
    return new BST(val);
  // Insert data
  if ( val > root -> data)
    root -> right = Insert(root -> right, val) ;
  else
    root -> left = Insert( root -> left , val );
  return root ;
}
// Search
BST* BST:: Search(BST *root,int val) {
  if (root == NULL || root -> data == val ) return root ;
  if ( val < root -> data  ) return Search(root -> left , val );
  return Search(root -> right , val );
}
// Find Min
BST* BST:: Min(BST *root) {
  BST *current = root;
  while( current && current -> left != NULL)
    current = current -> left ;
  return current;
}
// Delete
BST* BST:: Delete(BST *root,int val ) {
  if ( root == NULL) return root ;
  if ( val < root -> data) root -> left = Delete(root -> left , val) ;
  else if ( val > root -> data) root -> right = Delete(root -> right , val) ;
  else {
    // one child or no child
    if ( root -> left == NULL) {
      BST *temp = root -> right ;
      free(root) ;
      return temp ;
    }
    else if ( root -> right == NULL) {
      BST *temp = root -> left ;
      free(root) ;
      return temp ;
    }
    /// find min and cut
    BST *temp = Min(root -> right) ;
    root -> data = temp -> data ;
    root -> right = Delete(root -> right , temp -> data);
  }
  return root ;
}
main() {
  BST b , *root = NULL ;
  int n ;
  cin >> n ;
  for(int i=0 ; i < n ;i ++ ) {
    int m ,k;
    scanf("%d %d",&k,&m);
    if ( k == 1)
      if ( root == NULL ) root = b.Insert(root,m);
      else b.Insert(root,m);
    else if (k == 2)
      if( b.Search(root,m) ) printf("1\n");
      else  printf("0\n");
    else if (k==3) b.Delete(root,m);
  }

}
