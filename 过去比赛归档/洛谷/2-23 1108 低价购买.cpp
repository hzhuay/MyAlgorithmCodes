#include<bits/stdc++.h>
using namespace std;
int a[5005],dp[5005],cnt[5005],n;
int main(){
	unsigned int ans1=0,ans2=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		dp[i]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++)
			if(a[i]<a[j])dp[i]=max(dp[i],dp[j]+1);
		if(dp[i]==1)cnt[i]=1;//*
		for(int j=1;j<i;j++){
			if(a[i]<a[j]&&dp[i]==dp[j]+1)cnt[i]+=cnt[j];
			else if(a[i]==a[j]&&dp[i]==dp[j])cnt[j]=0;
		}
		if(ans1<dp[i])ans1=dp[i];
	}	
	for(int i=1;i<=n;i++)
		if(dp[i]==ans1)ans2+=cnt[i];
	printf("%u %u",ans1,ans2);
	return 0;
}
