#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;
int mr[5]={1,0,0,-1},mc[5]={0,1,-1,0};
int res[maxn*maxn+5],top,cur,ans[maxn+5][maxn+5];
char di[maxn+5][maxn+5];
bool vis[maxn+5][maxn+5];
struct Step{
	int r,c,step;
	Step(int r,int c,int s):r(r),c(c),step(s){}
};
queue<Step>q;
void bfs(){
	while(!q.empty()){
		Step s=q.front();
		for(int i=0;i<4;i++){
			int tmpr=s.r+mr[i],tmpc=s.c+mc[i];
			if(di[s.r][s.c]!=di[tmpr][tmpc]&&!vis[tmpr][tmpc]){
				q.push(Step(tmpr,tmpc,s.step+1));
				res[top]=++cur;
				vis[tmpr][tmpc]=true;
				ans[tmpr][tmpc]=top;
			}
		}
		q.pop();
	}
}
int main(){
	memset(vis,1,sizeof(vis));
	int n,m,askr,askc;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",di[i]+1);
		for(int j=1;j<=n;j++)
			vis[i][j]=false;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(!vis[i][j]){
				q.push(Step(i,j,1));
				vis[i][j]=true;
				cur=1;res[top]=cur;
				ans[i][j]=top;
				bfs();
				top++;
			}
	for(int i=0;i<m;i++){
		scanf("%d %d",&askr,&askc);
		printf("%d\n",res[ans[askr][askc]]);
	}
	return 0;
} 
