#include<stdio.h>
#include<list>
#include<iterator>
#include<iostream>
#include<string.h>
using namespace std;
int main(int argc, char const *argv[])
{
  /* code */
  int n;
  list<int> list;
  scanf("%d",&n);
  for(int i=0; i<n ;i++) {
    char s[20];
    int num ;
    scanf("%s",s);
    // printf("%s\n%d\n",s ,num);
    if( !strcmp(s,"ri") ) {
      scanf("%d",&num);
      list.push_back(num);
    }
    if( !strcmp(s,"li") ) {
      scanf("%d",&num);
      list.push_front(num);
    }

    if( !strcmp(s,"lr") ) {
      list.push_back( list.front() );
      list.pop_front();
    }
    if( !strcmp(s,"rr") ) {
      list.push_front( list.back() );
      list.pop_back();
    }
  }
  for(auto itr = list.begin(); itr != list.end() ;itr++)
    cout << *itr << endl ;
  return 0;
}
