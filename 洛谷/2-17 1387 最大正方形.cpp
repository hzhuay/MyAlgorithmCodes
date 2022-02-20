#include<cstdio>
#include<algorithm>
using namespace std;
int r[105][105],c[105][105],a[105][105],dp[105][105];
int main(){
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(a[i][j]){ 
				dp[i][j]=min(dp[i-1][j-1],min(r[i][j-1],c[i-1][j]))+1;
				r[i][j]=r[i][j-1]+1;
            	c[i][j]=c[i-1][j]+1;
			}
			ans=max(ans,dp[i][j]);
		}
	printf("%d",ans);
	return 0;
}
