#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=50+5;
const int maxt=200+5;
const int INF=1000000000;
int t[maxn],dp[maxt][maxn];
bool has_train[maxt][maxn][2];
int main(){
//	freopen("in.txt","r",frontdin);
	int n,T,M0,M1,kase=0,d;
	while(scanf("%d",&n),n){
		scanf("%d",&T);
		for(int i=1;i<n;i++)scanf("%d",&t[i]);
		scanf("%d",&M0);
		for(int i=0;i<M0;i++){
			scanf("%d",&d);
			for(int j=1;j<=n-1;j++){
				if(d<=T)has_train[d][j][0]=1;
				d+=t[j];
			}
		}
		scanf("%d",&M1);
		for(int i=0;i<M1;i++){
			scanf("%d",&d);
			for(int j=n-1;j>0;j--){
				if(d<=T)has_train[d][j+1][1]=1;
				d+=t[j];
			}
			
		}
		for(int i=n-1;i>=0;i--)
			dp[T][i]=INF;
		dp[T][n]=0;//±ØÒª£¿ 
		for(int i=T-1;i>=0;i--){
			for(int j=1;j<=n;j++){
				dp[i][j]=dp[i+1][j]+1;
				if(j<n&&has_train[i][j][0]&&i+t[j]<=T)
					dp[i][j]=min(dp[i][j],dp[i+t[j]][j+1]);//ÓÒ 
				if(j>1&&has_train[i][j][1]&&i+t[j-1]<=T)
					dp[i][j]=min(dp[i][j],dp[i+t[j-1]][j-1]);//×ó 
			}
		}
		printf("Case Number %d: ",++kase);
		if(dp[0][1]>=INF)puts("impossible");
		else printf("%d\n",dp[0][1]);
		memset(has_train,0,sizeof(has_train));
		memset(dp,0,sizeof(dp));
		memset(t,0,sizeof(t));
	}
	return 0;
} 
