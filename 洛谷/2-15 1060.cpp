#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=30000; 
int v[maxn+5],p[maxn+5],dp[2][maxn+5];
int main(){
	int n,m,i,ans=0;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
		scanf("%d %d",&v[i],&p[i]);
	for(i=0;i<m;i++){
		for(int x=0;x<=n;x++)
			dp[1][x]=dp[0][x];//¹ö¶¯Êý×é 
		for(int j=0;j<=n-v[i];j++)
				dp[0][j+v[i]]=max(dp[1][j]+p[i]*v[i],dp[0][j+v[i]]);
	}
	for(i=0;i<=n;i++)if(ans<dp[0][i])ans=dp[0][i];
	printf("%d",ans);
	return 0;
}
