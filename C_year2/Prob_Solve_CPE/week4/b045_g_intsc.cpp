#include<stdio.h>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std ;
#define LP(i,a,n) for(int i=a; i <n ; i++)
#define lp(i,n)  LP(i,0,n)

vector< pair<int,int> > v;
main() {
  int n, a, b;
  scanf("%d",&n);
  lp(i,n) {
    scanf("%d %d",&a,&b);
    v.push_back( make_pair(a,b) );
  }
  int count = 0 ;int job_done = 0 ;
  sort( v.begin() , v.end());
  LP(i,1,n) {
    // printf("%d %d\n",v[i].first,v[i].second);
    if( v[i].first >= v[ job_done ].second )
     count++, job_done = i;
  }
  printf("%d",++count);
}
