#include<cstdio>
const int N=105;
const int M=10005;
int p[N],dp[2][M];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&p[i]);
	for(int i=0;i<n;i++){
		for(int j=0;j<=m;j++)dp[1][j]=dp[0][j];//¹ö¶¯Êý×é 
		dp[0][p[i]]=dp[1][p[i]]+1;
		for(int j=p[i]+1;j<=m;j++)
			dp[0][j]=dp[1][j]+dp[1][j-p[i]];
	}
	printf("%d",dp[0][m]);
	return 0;
}
