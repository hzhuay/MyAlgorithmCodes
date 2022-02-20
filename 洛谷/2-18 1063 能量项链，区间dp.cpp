#include<bits/stdc++.h>
using namespace std;
const int maxn=2*100+5;
int a[maxn],dp[maxn][maxn];
int main(){
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i+n]=a[i];
	}
	for(int t=1;t<n;t++)
		for(int i=1,j=i+t;j<2*n&&i<2*n;i++,j=i+t)
			for(int k=i;k<j;k++)
				dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1]);
	for(int i=1;i<=n;i++)ans=max(ans,dp[i][i+n-1]);
	printf("%d",ans);
	return 0;
}
