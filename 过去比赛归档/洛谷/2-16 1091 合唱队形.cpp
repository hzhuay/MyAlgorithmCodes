#include<bits/stdc++.h>
using namespace std;
const int maxn=100000;
int a[maxn+5],dp1[maxn+5],dp2[maxn+5];
int main(){
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),dp1[i]=dp2[i]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<i;j++)
			if(a[i]>a[j])
			dp1[i]=max(dp1[i],dp1[j]+1);
	for(int i=n-1;i>0;i--)
		for(int j=n;j>i;j--)
			if(a[i]>a[j])
				dp2[i]=max(dp2[i],dp2[j]+1);
	for(int i=1;i<=n;i++)ans=max(ans,dp1[i]+dp2[i]-1);
	printf("%d",n-ans);
	return 0;
}
