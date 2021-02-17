#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  /* code */
  list<int> list1 ;
  int n;
  scanf("%d",&n);
  for(int i=0 ;i<n ;i++) {
    char c,c2;
    int num ;
    scanf(" %c %d",&c,&num);
    // printf("%c %d\n",c,num);
    switch (c)
    {
    case 'I':
      list1.push_front(num);
      break;

    case 'D':
     if (list1.size() < num) continue;
     list<int>::iterator itr = list1.begin();
     for(int i=1 ; i<num ;i++,itr++);
     list1.erase(itr);
     break;
    }
  }
  for(auto itr = list1.begin(); itr != list1.end() ;itr++)
    cout << *itr << endl ;
  return 0;
}
