///N<=1120, 有187个素数，最大为1117 
#include<cstdio>
#include<cstring>
#include<cmath> 
bool vis[1200];
int prime[200],ans;
int dp[1200][15];
void build_prime(){
	int n=1120;
	int m=sqrt(n+0.5);
	for(int i=2;i<=m;i++)
		if(!vis[i])
			for(int j=i*i;j<=n;j+=i)
				vis[j]=true;
	int k=0;
	for(int i=2;i<=n;i++)if(!vis[i])prime[k++]=i;
	//printf("%d %d\n",k,prime[k-1]); 
}                     
void init(){
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=0;i<187;i++)//prime[i]=2,3,5,7,9,......,1117
		for(int j=14;j;j--)//j=14,13,12,11,......,1
			for(int k=prime[i];k<=1120;k++)//k=prime[i],prime[i]+1,prime[i]+2,...,1120
				dp[k][j]+=dp[k-prime[i]][j-1];
}
int main(){
	build_prime();
	init();
	int N,K;
	while(scanf("%d%d",&N,&K),N!=0){
		printf("%d\n",dp[N][K]);
	}
	return 0;
}
