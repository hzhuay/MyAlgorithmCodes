#include<bits/stdc++.h>
using namespace std;
const int maxn=100000;
int a[maxn+5],dp[maxn+5]={1};
int main(){
	int n,ans1=0,ans2=0;
	while(scanf("%d",&a[n])==1)n++;
	for(int i=1;i<n;i++){
		dp[i]=1;
		for(int j=0;j<i;j++)
			if(a[i]<=a[j])
			dp[i]=max(dp[i],dp[j]+1);
	}
	for(int i=0;i<n;i++)ans1=max(ans1,dp[i]);
	
	for(int i=1;i<n;i++){
		dp[i]=1;
		for(int j=0;j<i;j++)
			if(a[i]>a[j])dp[i]=max(dp[i],dp[j]+1);
	}
	for(int i=0;i<n;i++)ans2=max(ans2,dp[i]);
	cout<<ans1<<'\n'<<ans2<<endl;
	return 0;
}
