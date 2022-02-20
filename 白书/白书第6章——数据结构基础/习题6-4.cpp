#include<cstdio>
#include<queue>
#include<cstring>
#include<string>
using namespace std;
struct Step{
	int x;
	int y;
	int steps;
	Step(int xx,int yy,int s):x(xx),y(yy),steps(s){}
};
queue<Step>q;
int mx[10]={-1,-2,-2,-1,1,2,2,1};
int my[10]={-2,-1,1,2,2,1,-1,-2};
int endx,endy;
char st[10],ed[10];
bool visited[10][10];
void bfs(){
	while(!q.empty()){
		Step s=q.front();
		if(s.x==endx&&s.y==endy){
			printf("To get from %s to %s takes %d knight moves.\n",st,ed,s.steps);
			return;
		}
		//printf("%d %d %d\n",s.x,s.y,s.steps);
		for(int i=0;i<8;i++){
			int tmpx=s.x+mx[i],tmpy=s.y+my[i];
			//printf("%d %d\n",tmpx,tmpy);
			if(tmpx>=0&&tmpx<8&&tmpy>=0&&tmpy<8&&visited[tmpx][tmpy]){
				q.push(Step(tmpx,tmpy,s.steps+1));
				visited[tmpx][tmpy]=0;
			}
		}
		q.pop();
	}
}
int main(){
	while(scanf("%s",st)!=EOF){
		memset(visited,1,sizeof(visited));
		q.push(Step(st[0]-'a',st[1]-'1',0));
		//printf("%s %d %d\n",start,start[0]-'a',start[1]-'1');
		scanf("%s",ed);
		//printf("%s %d %d\n",end,end[0]-'a',end[1]-'1');
		endx=ed[0]-'a';endy=ed[1]-'1';
		bfs();
		while(!q.empty())q.pop();
	}
	return 0;
}
