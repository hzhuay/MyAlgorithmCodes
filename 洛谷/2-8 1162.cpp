#include<bits/stdc++.h>
using namespace std;
struct Step{
	int r,c;
	Step(int r,int c):r(r),c(c){}
};
const int maxn=35;
int mr[5]={1,0,0,-1},mc[5]={0,1,-1,0},Map[maxn][maxn];
bool vis[maxn][maxn];
queue<Step>q;
void bfs(){
	while(!q.empty()){
		Step s=q.front();
		for(int i=0;i<4;i++){
			int tmpr=s.r+mr[i],tmpc=s.c+mc[i];
			if(vis[tmpr][tmpc]){
				q.push(Step(tmpr,tmpc));
				vis[tmpr][tmpc]=false;
			}
		}
		q.pop();
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<34;i++)
		for(int j=1;j<34;j++)
			vis[i][j]=true;
	for(int i=2;i<n+2;i++)
		for(int j=2;j<n+2;j++){
			scanf("%d",&Map[i][j]);
			if(Map[i][j])vis[i][j]=false;
		}
	q.push(Step(1,1));
	vis[1][1]=false;
	bfs();
	for(int i=2;i<n+2;i++)
		for(int j=2;j<n+2;j++)
			if(!vis[i][j])printf("%d%c",Map[i][j]," \n"[j==n+1]);
			else printf("2%c"," \n"[j==n+1]);
	return 0;
}
