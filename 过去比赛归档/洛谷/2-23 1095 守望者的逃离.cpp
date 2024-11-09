#include<bits/stdc++.h>
using namespace std; 
int dp[300005];
int main(){
	int M,S,T;
	scanf("%d%d%d",&M,&S,&T);
	for(int i=1;i<=T;i++){
		if(M>=10){
			dp[i]=max(dp[i],dp[i-1]+60);
			M-=10;
		}else {
			dp[i]=dp[i-1];
			M+=4;
		}
	}
	for(int i=1;i<=T;i++)
		dp[i]=max(dp[i],dp[i-1]+17);
	if(dp[T]>=S){
		while(dp[T]>=S)T--;
		printf("Yes\n%d",T+1);
	}else{
		printf("No\n%d",dp[T]);
	}
	return 0;
}
