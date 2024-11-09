#include<bits/stdc++.h>
using namespace std;
const int P=100003;
int dp[100005];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	dp[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k;j++){
			if(i-j>=0)dp[i]+=dp[i-j];
			dp[i]%=P;
		}
	printf("%d",dp[n]);
	return 0;
}
