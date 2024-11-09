#include<cstdio>
int a[205][205],dp[205][205];
inline int max(int a,int b,int c){
	int tmp=a;
	if(tmp<b)tmp=b;
	if(tmp<c)tmp=c;
	return tmp;
}
int main(){
	int n,m;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			dp[i][j]=max(dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1])+a[i][j];
	printf("%d",max(dp[m][n/2+1],dp[m][n/2],dp[m][n/2+2]));
	return 0;
}
