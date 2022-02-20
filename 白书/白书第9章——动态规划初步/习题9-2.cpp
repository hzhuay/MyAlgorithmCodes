//»ØËİ+dp? 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=45;
int dp[maxn][maxn][maxn][maxn];
int mp[maxn][5],top[5],n;
bool vis[maxn];
int DP(int k){
	int &ans=dp[top[1]][top[2]][top[3]][top[4]];
	if(ans!=-1||k>=5)return ans;
	ans=0;
	for(int i=1;i<=4;i++){
		if(top[i]==n)continue;
		top[i]++;
		int tmp=mp[top[i]][i];
		if(vis[tmp]){
			vis[tmp]=0;
			ans=max(ans,DP(k-1)+1);
			vis[tmp]=1;
		}else{
			vis[tmp]=1;
			ans=max(ans,DP(k+1));
			vis[tmp]=0;
		}
		top[i]--;
	}
	return ans;
}
int main(){
	while(scanf("%d",&n),n){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=4;j++)
				scanf("%d",&mp[i][j]);
		memset(dp,-1,sizeof(dp));
		printf("%d\n",DP(0));
		memset(vis,0,sizeof(vis));
		memset(top,0,sizeof(top));
	}
	return 0;
}
