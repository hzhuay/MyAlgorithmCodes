#include<cstdio>
#define M 10005
#define N 105
int v[N],p[N],dp[2][M];
int main(){
	int n,m,i,ans=0;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d %d",&v[i],&p[i]);
	for(i=1;i<=n;i++){
		for(int x=0;x<=m;x++)
			dp[1][x]=dp[0][x];//滚动数组 
		for(int j=0;j<=m-v[i];j++)
			if(dp[0][j+v[i]]<dp[1][j]+p[i])
				dp[0][j+v[i]]=dp[1][j]+p[i];
	}
	for(i=0;i<=m;i++)if(ans<dp[0][i])ans=dp[0][i];
	printf("%d",ans);
	return 0;
}
