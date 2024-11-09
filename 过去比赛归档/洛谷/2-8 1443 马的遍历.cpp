#include<bits/stdc++.h>
using namespace std;
struct Step{
	int r,c,steps;
	Step(int r,int c,int s):r(r),c(c),steps(s){}
};
const int maxn=410;
int mr[10]={1,2,2,1,-1,-2,-2,-1},mc[10]={-2,-1,1,2,2,1,-1,-2};
int ans[maxn][maxn];
bool vis[maxn][maxn];
queue<Step>q;
void bfs(){
	while(!q.empty()){
		Step s=q.front();
		for(int i=0;i<8;i++){
			int tmpr=s.r+mr[i],tmpc=s.c+mc[i];
			if(vis[tmpr][tmpc]){
				ans[tmpr][tmpc]=s.steps+1;
				q.push(Step(tmpr,tmpc,s.steps+1));
				vis[tmpr][tmpc]=false;
			}
		}
		q.pop();
	}
}
int main(){
	memset(ans,-1,sizeof(ans));
	int n,m,sr,sc;
	scanf("%d%d%d%d",&n,&m,&sr,&sc);
	for(int i=2;i<n+2;i++)
		for(int j=2;j<m+2;j++)
			vis[i][j]=true;
	q.push(Step(++sr,++sc,0));
	ans[sr][sc]=0;
	vis[sr][sc]=false;
	bfs();
	for(int i=2;i<n+2;i++){
		for(int j=2;j<m+2;j++)
			printf("%-5d",ans[i][j]);
		puts("");
	}	
	return 0;
}
