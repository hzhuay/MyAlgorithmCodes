#include<cstdio>
#include<algorithm>
using namespace std;
int a[3000][3000],b[5000],dp[3000][3000];
int main(){
	int n,h,d,k,l;
	scanf("%d%d%d",&n,&h,&d);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d",&l);
			a[i][l]++;
		}
	}
	for(int j=h;j>=1;j--){
		for(int i=1;i<=n;i++){
			dp[i][j]=max(b[j+d],dp[i][j+1])+a[i][j];
			if(dp[i][j]>b[j])
			b[j]=dp[i][j];
		}
	}
	printf("%d",b[1]);
}	
