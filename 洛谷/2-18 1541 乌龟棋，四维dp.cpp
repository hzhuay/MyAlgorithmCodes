#include<cstdio>
#include<algorithm>
using namespace std;
int a[400],b[5],dp[50][50][50][50];
int main(){
	int n,m,tmp;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=0;i<m;i++){
		scanf("%d",&tmp);
		b[tmp]++;
	}
	dp[0][0][0][0]=a[1];
	for(int i=0;i<=b[1];i++)
		for(int j=0;j<=b[2];j++)
			for(int k=0;k<=b[3];k++)
				for(int l=0;l<=b[4];l++){
					tmp=1+i+2*j+3*k+4*l;
					if(i)dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j][k][l]+a[tmp]);
					if(j)dp[i][j][k][l]=max(dp[i][j][k][l],dp[i][j-1][k][l]+a[tmp]);
					if(k)dp[i][j][k][l]=max(dp[i][j][k][l],dp[i][j][k-1][l]+a[tmp]);
					if(l)dp[i][j][k][l]=max(dp[i][j][k][l],dp[i][j][k][l-1]+a[tmp]);
				}
	printf("%d",dp[b[1]][b[2]][b[3]][b[4]]);
	return 0;
}
