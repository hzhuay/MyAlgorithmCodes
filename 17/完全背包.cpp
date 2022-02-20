#include<cstdio>
#include<algorithm>
#define M 10005
#define N 105
using namespace std;
int v[N],p[N],dp[M];
int main(){
	int i,ans=0,j,n,m;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d %d",&v[i],&p[i]);
	for(i=1;i<=n;i++){
		for(j=0;j<=m-v[i];j++)
			dp[j+v[i]]=max(dp[j+v[i]],dp[j]+p[i]);	
	}
	for(i=0;i<=m;i++)if(ans<dp[i])ans=dp[i];
	printf("%d",ans);
	return 0;
}
