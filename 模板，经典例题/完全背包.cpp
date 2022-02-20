#include<cstdio>
#include<algorithm>
using namespace std;
int t[100005],m[10005],dp[100005];
int main(){
	int T,M;
	scanf("%d%d",&T,&M);
	for(int i=0;i<M;i++)
		scanf("%d%d",&t[i],&m[i]);
	for(int i=0;i<M;i++){
		for(int j=t[i];j<=T;j++)
			dp[j]=max(dp[j-t[i]]+m[i],dp[j]);	
	}
	printf("%d",dp[T]);
	return 0;
}
