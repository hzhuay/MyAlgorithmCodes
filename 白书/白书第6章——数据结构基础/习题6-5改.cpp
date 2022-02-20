#include<cstdio>
#include<queue>
#include<cstring>
#define maxn 25
using namespace std;
int map[maxn][maxn],k,r,c;
int mx[5]={1,0,-1,0},my[5]={0,1,0,-1};
int visited[maxn][maxn][maxn];
struct Step{
	int x;
	int y;
	int steps;
	int b;
	Step(int xx,int yy,int s,int bb):x(xx),y(yy),steps(s),b(bb){}
};
queue<Step>q;
void dfs(){
	while(!q.empty()){
		Step s=q.front();
		if(s.x==r&&s.y==c){
			printf("%d\n",s.steps);
			return;
		}
		//printf("%d %d %d %d\n",s.x,s.y,s.steps,s.b);
		for(int i=0;i<4;i++){
			int x=s.x+mx[i],y=s.y+my[i],step=s.steps+1,b=s.b+1;
			if(!map[x][y]&&visited[x][y][0]){
				visited[x][y][0]=0;
				q.push(Step(x,y,step,0));
			}else if(map[x][y]&&s.b<k&&visited[x][y][b]){
				visited[x][y][b]=0;
				q.push(Step(x,y,step,b));
			}
		}
		q.pop();
	}
	puts("-1");
	return;
}
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int kase;
	scanf("%d",&kase);
	while(kase--){
		memset(map,0,sizeof(map));
		memset(visited,0,sizeof(visited));
		scanf("%d%d%d",&r,&c,&k);
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++){
				scanf("%d",&map[i][j]);
				for(int p=0;p<maxn;p++)
					visited[i][j][p]=1;
			}
		q.push(Step(1,1,0,0));
		visited[1][1][0]=0;
		dfs();
		while(!q.empty())q.pop();
	}
	return 0;
}
