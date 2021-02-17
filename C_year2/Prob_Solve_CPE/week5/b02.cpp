#include<bits/stdc++.h>
using namespace std ;

class BST {
  int data ;
  BST *left, *right ;
  public :
  BST();
  BST(int);
  BST* Insert(BST *, int );
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
// Inorder
void BST :: Inorder(BST *root,int level) {
  if ( !root ) return ;
  Inorder(root -> right,level+1) ;
  cout << string(level*3,'.') + '*' + ' ' << root -> data << endl ;
  Inorder( root -> left ,level+1);
}

main() {
  BST b , *root = NULL ;
  int n ;
  cin >> n ;
  for(int i=0 ; i < n ;i ++ ) {
    int m ;
    cin >> m ;
    if ( root == NULL ) root = b.Insert(root,m);
    else b.Insert(root,m);
  }
  b.Inorder(root,0);
}
