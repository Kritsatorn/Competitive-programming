#include<stdio.h>
#include<algorithm>
#include <utility>
#include<vector>
using namespace std;

int k ,n ,m ,Max ,arr[10010];
vector< pair<int, int> > vect;

int main(int argc, char const *argv[])
{
  int from ,to ;
  scanf("%d %d %d",&k,&n,&m);
  for(int i = 0 ; i < m ; i++) {
    scanf("%d %d",&from,&to);
    vect.push_back( make_pair(from,to) );
  }

  sort(vect.begin(),vect.end());

  for(int i = 0 ; i < m ; i++) {
    from  = vect[i].first;
    to    = vect[i].second;

    if ( ( arr[from] !=0 && arr[from] < k ) || from == 1) {
      if (arr[to] != 0)
        arr[to] = arr[from] + 1 < arr[to] ? arr[from] + 1 : arr[to] ;
      else
        arr[to] = arr[from] + 1;
      Max = to > Max ? to : Max ;
    }
  }

  printf("%d",Max);
  return 0;
}
