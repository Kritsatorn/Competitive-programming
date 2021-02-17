#include<bits/stdc++.h>
using namespace std ;
struct Work {
  int S , E ,idx;
} ;
bool cmp (Work a, Work b) { return a.E < b.E;}
bool cmp_idx (Work a, Work b) { return a.idx < b.idx;}
bool check(Work* work,int n,int idx,int* ans,int who) {
 
  for(int i=0 ; i < idx ; i++) {
    if ( who == ans[i]) {
      if ( work[i].S < work[idx].S
        && work[idx].S < work[i].E
        && work[i].E < work[idx].E
      ) return false ;
      else if ( work[idx].S < work[i].S
        && work[i].S < work[idx].E
        && work[idx].E < work[i].E
      ) return false ;
      else if (
        work[i].S < work[idx].S
        && work[idx].E < work[i].E
      ) return false ;
      else if (
        work[idx].S < work[i].S
        && work[i].E < work[idx].E
      ) return false ;
    }
  }
//  printf("idx : %d who: %d  = ",idx,who);
//   for(int i=0 ; i<idx;i++)printf("%d ",ans[i]);
//   printf("\n");
  return true ;
}
bool fuck(Work* work,int n,int idx,int* ans) {
  if ( idx >= n ) return true ;
  // for(int i=0 ; i <n ; i++)
  //     printf("%d %d\n",work[i].S,work[i].E);
  bool path_a = false ,path_b = false  ;
  if ( check(work,n,idx,ans,1) ) {
    ans[idx] = 1;
    path_a = fuck(work,n,idx+1,ans);
    if ( path_a ) {
      // printf("1 ");
      return true;
    }
  }
  if ( check(work,n,idx,ans,2) ) {
    ans[idx] = 2;
    path_b = fuck(work,n,idx+1,ans);
    if ( path_b ) {
      // printf("2 ");
      return true;
    }
  }
  // printf("hi %d : ",idx);
  // printf("A : %d || B : %d",path_a,path_b);
  // for(int i=0 ; i<idx ; i++) printf("%d ",ans[i]);
  // printf("\n");
  return false ;
  // if ( path_a ) {
  //   ans[idx] = 1; return true;
  // }
  // else if ( path_b ) {
  //   ans[idx] = 2; return true;
  // }
  // else {
  //   return false ;
  // }
}
main() {
  int test_case ,count_case = 0;
  scanf("%d",&test_case);
  while (count_case++ < test_case ) {
    int n ,s,e;
    Work work[1010] ;
    int ans[1010] ;
    scanf("%d",&n) ;
    for(int i=0 ; i <n ; i++)
      scanf("%d %d",&work[i].S,&work[i].E) , work[i].idx = i ;
      // int idx = 1 ; ans[0] = 1 ;
      // bool x = check(work,n,idx,ans,1) ;
      // printf("%d",x);
    // sort(work,work+n,cmp);
    printf("Case #%d: ",count_case);
    if ( fuck(work,n,0,ans) )
      for(int i=0 ; i<n;i++)
      if ( ans[i] == 1)
        printf("C");
      else
        printf("J");
    else
      printf("IMPOSSIBLE");
    printf("\n");

  }
}