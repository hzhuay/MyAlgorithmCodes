#include<cstdio>
#include<algorithm>
using namespace std;
int t[1005],m[105],dp[1005];
int main(){
	int T,M;
	scanf("%d%d",&T,&M);
	for(int i=0;i<M;i++)
		scanf("%d%d",&t[i],&m[i]);
	for(int i=0;i<M;i++){
		for(int j=T;j>=t[i];j--)
			dp[j]=max(dp[j],dp[j-t[i]]+m[i]);
	}
	printf("%d",dp[T]);
	return 0;
}
