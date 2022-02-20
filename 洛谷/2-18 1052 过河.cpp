#include<bits/stdc++.h>
using namespace std;
const int maxn=500000;
int a[105],d[105],dp[maxn],mark[maxn];
int main(){
	int L,S,T,M,ans=INT_MAX;
	scanf("%d%d%d%d",&L,&S,&T,&M);
	for(int i=1;i<=M;i++)scanf("%d",&a[i]);
	sort(a+1,a+M+1);
	for(int i=1;i<=M;i++)d[i]=a[i]-a[i-1];
	//for(int i=1;i<=M;i++)printf("%d %d\n",a[i],d[i]);
	for(int i=1;i<=M;i++){
		if(d[i]>=2520)a[i]=a[i-1]+d[i]%2520+2520;
			//a[i]=a[i-1]+(a[i]-a[i-1])%2520;
		else a[i]=a[i-1]+d[i];
		//while(a[i]-5040>a[i-1])a[i]-=2520;
		mark[a[i]]++;
	}
	L=a[M];
	for(int i=0;i<=L+T;i++)dp[i]=M;
	dp[0]=0;
	for(int i=S;i<=L+T;i++){
		for(int j=S;j<=T;j++){
			if(i-j>=0)dp[i]=min(dp[i],dp[i-j]);
			dp[i]+=mark[i];
		}
	}
	for(int i=L;i<L+T;i++)ans=min(ans,dp[i]);
	//for(int i=1;i<=M;i++)printf("%d %d %d\n",a[i],d[i],dp[a[i]]);
	printf("%d",ans);
	//for(int i=0;i<=L+M;i++)printf("%d ",dp[i]);
	return 0;
}
