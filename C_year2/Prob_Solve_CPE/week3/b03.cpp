// #include <bits/stdc++.h>
#include<stdio.h>
#include<list>
#include<iterator>
#include<iostream>
using namespace std;
struct List {
  // int data ;
  struct List *next,*prev ;
};

int main(int argc, char const *argv[])
{
  list<int> list[100010] ;
  int n;
  scanf("%d",&n);
  while(n-- > 0) {
    int num, brok ;
    char c;
    scanf(" %c %d %d",&c,&num,&brok);
    // printf("%c %d %d\n",c,num,brok);
    switch (c)
    {
    case 'N':
      list[brok].push_back(num);
      break;

    case 'M':
      //list<int>::iterator itr = list[num].begin();
      while(list[num].size() != 0 ) {
        list[brok].push_back(list[num].front());
        list[num].pop_front();
        // printf("dfd\n");
      }
      break;
    }
  }
  for(int i=1 ; i<=100000;i++)
  for(auto itr = list[i].begin(); itr != list[i].end() ;itr++)
    printf("%d\n",*itr);
  //   cout << *itr << endl ;
  return 0;
}
