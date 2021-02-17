#include<bits/stdc++.h>
using namespace std ;
int n ;
struct Work{
  int s ,t, w ,idx;
}arr_work[1010];
bool comp(Work lhs, Work rhs) { return lhs.s < rhs.s ; }
void printLIS(vector<struct Work> & arr){
    int count = 0;
    for (struct Work x : arr)
        count += x.w ;
    printf("%d\n%d\n",count,arr.size());
    for (struct Work x : arr)
        cout << x.idx << " ";
    cout << endl;
}

void fuck() {
  vector< vector< struct Work>> L(n);
  L[0].push_back(arr_work[0]) ;
  for(int i=1 ; i <n ; i++) {
    int currnt_Max = INT_MIN ;
    for(int j=0 ; j < i ; j ++) {
      int Latest = INT_MIN , Latest_Sum = 0;
      for(int k=0 ; k < L[j].size() ; k++)
        Latest = max(Latest , L[j][k].t) , Latest_Sum += L[j][k].w;
      if ( arr_work[i].s >= Latest && ( Latest_Sum > currnt_Max) )
         L[i] = L[j] , currnt_Max = Latest_Sum;
    }
    L[i].push_back(arr_work[i]);
  }

  vector<struct Work> max = L[0];
  int maxx = INT_MIN ;
  for (vector<struct Work> x : L) {
    int count = 0;
    for (struct Work y : x) count += y.w ;
    if ( count > maxx) max = x , maxx = count;
    // printf("%dasd\n",count);
  }
  printLIS(max);
}

main() {
  scanf("%d",&n);
  for(int i=0 ; i<n ;i ++) {
    scanf("%d %d %d",&arr_work[i].s,&arr_work[i].t,&arr_work[i].w) ;
    arr_work[i].idx = i + 1;
  }
  sort(arr_work , arr_work + n , comp);
  fuck();

}