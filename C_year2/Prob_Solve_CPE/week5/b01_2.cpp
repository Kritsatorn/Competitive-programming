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
  }

}
