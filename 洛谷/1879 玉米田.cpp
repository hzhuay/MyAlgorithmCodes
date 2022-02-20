#include<cstdio>
#include<algorithm>
using namespace std;
const int P=1000000000;
int a[15][15],F[15],dp[15][1<<12+5];//dp[i][j]指第i行状态为j时，前i行的合法方案数 
bool mark[1<<12+5];//mark[i]记录i这个状态是否合法 
int main(){
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			F[i]=(F[i]<<1)+a[i][j];
		}
	int M=1<<m;
	for(int i=0;i<M;i++)
		mark[i]=(!(i&(i<<1)))&&(!(i&(i>>1)));//预处理 
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<M;j++){//枚举一行所有可能的状态 
			if(mark[j]&&((j&F[i])==j)){//这个状态合法&&所有该种草的地方可以种草 
				for(int k=0;k<M;k++){//枚举上一行的所有状态 
					if((k&j)==0){//该行若与上一行的某种状态不矛盾 
						dp[i][j]=(dp[i][j]+dp[i-1][k])%P;
					}
				}
			}
		}
	}
	for(int i=0;i<M;i++)
		ans=(ans+dp[n][i])%P;//前n行所有合法方案数累加 
	printf("%d",ans);
	return 0;
}
