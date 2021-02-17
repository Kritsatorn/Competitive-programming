#include<bits/stdc++.h>
using namespace std ;
int X , Y , T , DirCat[1010][3] ;
int Dir[4][2] = { {-1,0} , {1,0} , {0,1} , {0,-1}  } ;
int mem[1010] ;
bool comp(int a, int b) { return (a < b); }
int Find(int time,int x , int y) {
  if ( mem[time] != 0 ) return mem[time] ;
  if ( time > T  ) return INT_MAX ;
  // return min({
  //   Find(time+1,x,y) , Find(time+1,x,y) , Find(time+1,x,y) , Find(time+1,x,y)
  // },comp);
  if ( x == DirCat[time][0] && y == DirCat[time][1]) return time ;
  int A , B ,C ,D ;
  A = Find(time+1,x-1,y) ; B =  Find(time+1,x+1,y);
  C = Find(time+1,x,y+1) ; D =  Find(time+1,x,y-1);
  printf("%d %d %d : ",time , x , y) ;
  printf("%d %d %d %d\n",A,B,C,D);
  return  min( { A,B,C,D},comp) ;
}
main() {
  int test_case ,count_case = 0;
  scanf("%d",&test_case);
  while (count_case++ < test_case ) {
    char S[1010] ;
    scanf("%d %d",&Y,&X);
    scanf("%s",S);
    int xs = Y , ys = X  ;
    T = strlen(S) ;
    for(int s = 0 ; s < T ; s ++) {
      switch(S[s]) {
        case 'W' : xs += 0 ; ys += -1 ;
        break ;
        case 'N' : xs += 1 ; ys += 0 ;
        break ;
        case 'E' : xs += 0 ; ys += 1 ;
        break ;
        case 'S' : xs += -1 ; ys += 0 ;
        break ;
      }
      DirCat[s][0] = xs ; DirCat[s][1] = ys ;
    }
    int ANS ;
    ANS = Find(0,0,0) ;
    cout << ANS << endl ;
  }
}