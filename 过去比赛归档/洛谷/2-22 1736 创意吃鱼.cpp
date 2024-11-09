#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2500+5;
int r[maxn][maxn],c[maxn][maxn],a[maxn][maxn],dp[maxn][maxn];
int main(){
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(a[i][j])
				dp[i][j]=min(dp[i-1][j-1],min(r[i][j-1],c[i-1][j]))+1;
			else{
				r[i][j]=r[i][j-1]+1;
            	c[i][j]=c[i-1][j]+1;
			}
			ans=max(ans,dp[i][j]);
		}
	memset(r,0,sizeof(r));
	memset(c,0,sizeof(c));
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
		for(int j=m;j>0;j--){
			if(a[i][j])
				dp[i][j]=min(dp[i-1][j+1],min(r[i][j+1],c[i-1][j]))+1;
			else{
				r[i][j]=r[i][j+1]+1;
            	c[i][j]=c[i-1][j]+1;
			}
			ans=max(ans,dp[i][j]);
		}
	printf("%d",ans);
	return 0;
}
