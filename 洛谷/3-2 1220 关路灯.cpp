#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N,C,p[55],x[55],dp[55][55][2],s[55];
int tol(int i,int j,int l,int r){return (x[j]-x[i])*(s[l]+s[N]-s[r-1]);} 
int main(){
	memset(dp,127,sizeof(dp));
	scanf("%d%d",&N,&C);
	for(int i=1;i<=N;i++){
		scanf("%d%d",&x[i],&p[i]);
		s[i]=s[i-1]+p[i];
	}
	dp[C][C][0]=dp[C][C][1]=0;
//dp[i][j][]为区间i,j的灯都关闭时人在i处或j处花费的电量 
	for(int j=C;j<=N;j++){//区间右边界 
		for(int i=j-1;i>0;i--){//区间左边界 
			dp[i][j][0]=min(dp[i+1][j][0]+tol(i,i+1,i,j+1),dp[i+1][j][1]+tol(i,j,i,j+1));
			dp[i][j][1]=min(dp[i][j-1][0]+tol(i,j,i-1,j),dp[i][j-1][1]+tol(j-1,j,i-1,j));
		}
	}
	printf("%d",min(dp[1][N][0],dp[1][N][1]));
	return 0;
}
