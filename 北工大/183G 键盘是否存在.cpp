#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#define MAXN 205
using namespace std;
int mx[5]={1,0,-1,0},my[5]={0,1,0,-1};
bool visited[MAXN][MAXN];//判重，true则已经扩展过 
char str[MAXN][MAXN];
struct Step{
	int x;
	int y;
	int steps;
	Step(int xx,int yy,int s):x(xx),y(yy),steps(s){}
};
queue<Step>q;//队列，Open列表 
void bfs(){
	while(!q.empty()){
		Step s=q.front();
		for(int k=0;k<4;k++){
			if(str[s.x+mx[k]][s.y+my[k]]=='K'){
				printf("Are you ");
				for(int i=0;i<=s.steps;i++)putchar('O');
				printf("K?\n");
				return;
			}
			else if(str[s.x+mx[k]][s.y+my[k]]=='O'&&!visited[s.x+mx[k]][s.y+my[k]]){
				q.push(Step(s.x+mx[k],s.y+my[k],s.steps+1));
				visited[s.x+mx[k]][s.y+my[k]]=1;
			}
		}
		q.pop();
	}
	puts("I have already eaten the keyboard.");
}
int main(){
	int i,j,n,m,kase;
	freopen("in.txt","r",stdin);
	scanf("%d",&kase);
	while(kase--){
		bool flag=1;
		scanf("%d %d",&n,&m);
		memset(visited,0,sizeof(visited));
		for(i=1;i<=n;i++)
			scanf("%s",str[i]+1);
		for(i=1;i<=n&&flag;i++)
			for(j=1;j<=m;j++)
				if(str[i][j]=='I'){
					q.push(Step(i,j,0));
					bfs(); 
					flag=0;
					break;
				}
		memset(str,0,sizeof(str));
		while (!q.empty())q.pop();
	}
	return 0;
}
