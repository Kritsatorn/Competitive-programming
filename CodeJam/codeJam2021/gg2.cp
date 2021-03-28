#include "stdio.h"
#include "string.h"
#define mINT 1000001

int MIN(int a,int b){return (a<b)?a:b;}

void doing(int t){
	char z[1001];
	int dp[1001][2] = {0};
	int x,y,Len;
	scanf("%d %d %s",&x,&y,z);
	Len = strlen(z);
	
	if(z[0] == '?'){
		dp[0][0] = dp[0][1] = 0;
	}
	else if(z[0] == 'C'){
		dp[0][0] = 0;
		dp[0][1] = mINT;
	}
	else if(z[0] == 'J') {
		dp[0][1] = 0;
		dp[0][0] = mINT;	
	}
	
	if(Len>=2){
		if(z[1] == '?'){
			if(z[0] == '?')
				dp[1][0] = dp[1][1] = 0;
			else{
				dp[1][0] = MIN(dp[0][0],dp[0][1]+y);
				dp[1][1] = MIN(dp[0][1],dp[0][0]+x);
			} 
				
		}
		else if(z[1] == 'C'){
			if(z[0] == '?')
				dp[1][0] = 0;
			else
				dp[1][0] = MIN(dp[0][0],dp[0][1]+y);
				
			dp[1][1] = mINT;
		}
		else if(z[1] == 'J'){
			if(z[0] == '?')
				dp[1][1] = 0;
			else
				dp[1][1] = MIN(dp[0][1],dp[0][0]+x);
				
			dp[1][0] = mINT;
		}
	}
	
	for(int i=2;i<Len;i++){
		if(z[i] == 'C'){
			dp[i][0] = MIN(dp[i-1][0] , dp[i-1][1]+y);
			dp[i][1] = mINT;
		}
		
		else if(z[i] == 'J'){
			dp[i][0] = mINT;
			dp[i][1] = MIN(dp[i-1][1] , dp[i-1][0]+x);
		}
		
		else if(z[i] == '?'){
			dp[i][0] = MIN(dp[i-1][0] , dp[i-1][1]+y);
			dp[i][1] = MIN(dp[i-1][1] , dp[i-1][0]+x);
		}
	}
	/*
	for(int i=0;i<Len;i++){
		printf("%d : C = %d  , J = %d\n",i,dp[i][0],dp[i][1]);
		
	}
	*/
	
	printf("Case #%d: %d\n",t,MIN(dp[Len-1][0],dp[Len-1][1]));
}

int main(){
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		doing(i);
	}
}
