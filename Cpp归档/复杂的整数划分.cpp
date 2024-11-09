#include<cstdio>
#include<cstring>
#define M 55
int a[M][M],b[M],c[M][M],dp[M][M];
int fa(int n,int m) {
	if(dp[n][m]>=0)return dp[n][m];
	if(n<1||m<1)return 0;
	if(n==1||m==1)return 1;
	if(n<m)return dp[n][m]=fa(n,n);
	if(n==m)return dp[n][m]=fa(n,m-1)+1;
	return dp[n][m]=fa(n,m-1)+fa(n-m,m);
}
int fb(int s,int n,int k) { //我要从s作为最小值把n分成k份
	int sum=n,i=1,per=0;
	if(k==0) {
		while(i<=11&&sum>=0) {
			sum-=i;
			i++;
		}
		for(int j=1; j<=i-2; j++)per+=fb(s,n,j);
		return per;
	} else if(k==1)return 1;
	else {
		while(a[s+1][k-1]<=n-s) {
			per+=fb(s+1,n-s,k-1);
			s++;
		}
		return per;
	}
}
int main() {
	//freopen("test.in","r",stdin);
	//freopen("test2.out","w",stdout);
	int n,m,i,j;
	memset(dp,-1,sizeof(dp));
	for(i=1; i<=26; i++) {
		a[i][1]=i;
		for(int j=2; j<=25; j++) {
			a[i][j]=a[i][j-1]+i+j-1;
		}
	}
	for(i=1; i<=50; i++)b[i]=fb(1,i,0);
	for(i=1; i<=50; i++)
		for(j=1; j<=i; j++)
			c[i][j]=fa(i,j);
	while(scanf("%d %d",&n,&m)!=EOF)
		printf("%d\n%d\n%d\n",c[n][m]-c[n][m-1],b[n],b[n]);
	return 0;
}
