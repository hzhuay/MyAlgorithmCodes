#include<bits/stdc++.h>
using namespace std;
const int maxn=300;
int a[maxn+5],s[maxn+5],dp1[maxn+5][maxn+5],dp2[maxn+5][maxn+5];
inline int d(int l,int r){return s[r]-s[l-1];}
int main(){
//	freopen("in.txt","r",stdin);
	int n,ans1=0,ans2=INT_MAX;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i+n]=a[i];
	}
	for(int i=1;i<=2*n;i++)s[i]=s[i-1]+a[i];
	for(int t=1;t<n;t++){
		for(int i=1,j=i+t;j<2*n&&i<2*n;i++,j=i+t){
			dp2[i][j]=INT_MAX;
			for(int k=i;k<j;k++){
				dp1[i][j]=max(dp1[i][j],dp1[i][k]+dp1[k+1][j]+d(i,j));
				dp2[i][j]=min(dp2[i][j],dp2[i][k]+dp2[k+1][j]+d(i,j));
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans1=max(ans1,dp1[i][i+n-1]);
		ans2=min(ans2,dp2[i][i+n-1]);
	}
	printf("%d\n%d",ans2,ans1);
	return 0;
}
