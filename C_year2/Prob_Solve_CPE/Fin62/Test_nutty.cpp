#include<bits/stdc++.h>
using namespace std;

char S[105];
char T[100005];
int Snum, Tnum;

int searchname(int ss,int tt,int namecount){
  printf("%d %d %d \n",tt,ss,namecount);
  if ( tt > Tnum - 1 ) return 0 ;
  if ( T[tt] == S[ss] )
{  if ( ss + 1 >=  Snum - 1){
    return 1 + searchname(0,tt+1,namecount + 1) ;}
  else {return searchname(ss+1,tt+1,namecount);}}
  else return searchname(ss,tt+1,namecount);
}

int main(){
  scanf("%s",S)  ;
  scanf("%s",T)  ;
  int Snum = strlen(S);
  int Tnum = strlen(T);
  int ss=0, tt=0, namecount=0;
  int countt = searchname(ss, tt, namecount);
  cout << countt << endl ;
  // cout << S << endl <<T << endl;
  // cout << Snum << " " << Tnum << endl;
}