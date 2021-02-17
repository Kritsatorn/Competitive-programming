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
  int getCount(BST* , int , int);
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
int BST:: getCount(BST *root, int low, int high) 
{ 
    // Base case 
    if (!root) return 0; 
  
    // Special Optional case for improving efficiency 
    if (root->data == high && root->data == low) 
        return 1; 
  
    // If current node is in range, then include it in count and 
    // recur for left and right children of it 
    if (root->data <= high && root->data >= low) 
         return 1 + getCount(root->left, low, high) + 
                    getCount(root->right, low, high); 
  
    // If current node is smaller than low, then recur for right 
    // child 
    else if (root->data < low) 
         return getCount(root->right, low, high); 
  
    // Else recur for left child 
    else return getCount(root->left, low, high); 
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
      printf("%d \n",b.getCount(root,m+1,200000));
  }

}
