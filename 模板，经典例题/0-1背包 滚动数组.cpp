#include<cstdio>
#include<algorithm>
using namespace std;
int t[1005],m[105],dp[2][1005];
int main(){
	int T,M;
	scanf("%d%d",&T,&M);
	for(int i=0;i<M;i++)
		scanf("%d%d",&t[i],&m[i]);
	for(int i=0;i<M;i++){
		for(int j=0;j<=T;j++)dp[1][j]=dp[0][j];//???? 
		for(int j=t[i];j<=T;j++)
			dp[0][j]=max(dp[1][j],dp[1][j-t[i]]+m[i]);
	}
	printf("%d",dp[0][T]);
	return 0;
}
