#include<stdio.h>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std ;
#define LP(i,a,n) for(int i=a; i <n ; i++)
#define lp(i,n)  LP(i,0,n)

vector< pair<int,int> > v;
main() {
  int Deadline = 0, Finish = 0 ,maxx = 0 , Day_10 = 10;
  int n, a, b;
  scanf("%d",&n);
  lp(i,n) {
    scanf("%d %d",&a,&b);
    v.push_back( make_pair(a,b) );
  }
  sort( v.begin() , v.end());
  lp(i,n) {
    Deadline  = v[i].first  ;
    Finish    += v[i].second ;
    int k = Finish - Deadline -10;
    maxx = maxx > k ? maxx : k ;
  }
  printf("%d",maxx * 1000);
}