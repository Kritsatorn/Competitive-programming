#include <bits/stdc++.h>
using namespace std;
long long int SEQ[] = {1, 5 , 10 , 25 , 50 } , MEM[30001][6], N, ANS;
long long int calc(int C , int K){
  if(K==5)return 0;
  if ( C <0)return 0;
    if(C == 0)return 1;

    long long int &A = MEM[C][K];
    if(A != -1)return A;
    A = 0;
    A = calc(C - SEQ[K],K)+calc(C , K+1);
    return A;
}
int main() {
  memset(MEM,-1,sizeof MEM);
	while(cin >> N){
		ANS = calc(N,0);
		if(ANS != 1)
			printf("There are %lld ways to produce %lld cents change.\n" , ANS , N);
		else
			printf("There is only 1 way to produce %lld cents change.\n" , N);
	}
	return 0;
}