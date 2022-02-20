#include<cstdio>
int fx,fy,ans;
//int tx[30],ty[30];
int mx[5]={1,0,-1,0},my[5]={0,1,0,-1};
bool vis[10][10];
void dfs(int x,int y){
	if(x==fx&&y==fy){
		ans++;
		return;
	}
	for(int i=0;i<4;i++){
		int tmpx=x+mx[i],tmpy=y+my[i];
		if(vis[tmpx][tmpy]){
			vis[tmpx][tmpy]=false;
			dfs(tmpx,tmpy);
			vis[tmpx][tmpy]=true;
		}
	}
}
int main(){
	int n,m,t,tx,ty,sx,sy;
	scanf("%d%d%d%d%d%d%d",&n,&m,&t,&sx,&sy,&fx,&fy);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			vis[i][j]=true;
	while(t--){
		scanf("%d%d",&tx,&ty);
		vis[tx][ty]=false;
	}
	vis[sx][sy]=false;
	dfs(sx,sy);
	printf("%d",ans);
	return 0;
}
