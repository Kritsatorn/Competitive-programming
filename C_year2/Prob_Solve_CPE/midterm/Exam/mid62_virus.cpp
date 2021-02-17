#include<bits/stdc++.h>
using namespace std ;
main() {
  list<int> list1 ;
  int pos = 0;
  int n, m ,num ;
  scanf("%d %d",&n,&m);
  for(int i=0 ; i < n ; i++) {
    scanf("%d",&num);
    list1.push_back(num);
  }
  char c; int k;
  list<int>::iterator it ;
  for(int i=0 ; i < m ;i++) {
    scanf(" %c",&c);
    switch (c)
    {
    case '1': pos = 0;
      break;
    case '2': pos = (pos+1) % ( list1.size() ) ;
      break;
    case '3':
      scanf("%d",&k);
      it = list1.begin();
      
      
      advance(it, pos);
      
      list1.insert(it,k) ;
      pos = (pos+1) % ( list1.size() ) ;
      break;
    case '4':
      scanf("%d",&k);
      it = list1.begin();

      advance(it, pos+1);
      list1.insert(it,k) ;
      
      break;
    }
  // for (list<int>::iterator i = list1.begin();
  //        i != list1.end();
  //        i++)
  //       cout << *i << " ";
  //       cout << "pos : " << pos << " " << list1.size() ; 
  //       cout << endl;
  }
  for (list<int>::iterator i = list1.begin();
         i != list1.end();
         i++)
        cout << *i << endl;

}