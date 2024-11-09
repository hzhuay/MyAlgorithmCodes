#include<bits/stdc++.h>
using namespace std;
const int maxn=100+5;
int mr[5]={1,0,0,-1},mc[5]={0,1,-1,0},Map[maxn][maxn],d[maxn][maxn];
bool vis[maxn][maxn];
void dfs(int r,int c,int cur){
	if(cur<=d[r][c])return;//哪怕少个=都会造成巨大的浪费，所以一定要带 
	else d[r][c]=cur;
	for(int i=0;i<4;i++){
		int tmpr=r+mr[i],tmpc=c+mc[i];
		if(!vis[tmpr][tmpc]&&Map[r][c]>=0&&Map[r][c]<Map[tmpr][tmpc]){
			vis[tmpr][tmpc]=true;
			dfs(tmpr,tmpc,cur+1);
			vis[tmpr][tmpc]=false;
		}
	}
}
int main(){
	memset(d,-1,sizeof(d));
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&Map[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			dfs(i,j,1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans=max(ans,d[i][j]);
	printf("%d",ans);
	return 0;
}
