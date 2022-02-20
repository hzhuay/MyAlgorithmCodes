#include<cstdio>
#include<cstring>
#include<queue>
#define MAXN 100005
using namespace std;
int N,K;
bool visited[MAXN];//判重，ture则已经扩展过 
struct Step{
	int x;
	int steps;
	Step(int xx,int s):x(xx),steps(s){}
};
queue<Step>q;//队列，Open列表 
int main(){
	scanf("%d %d",&N,&K);
	memset(visited,0,sizeof(visited));
	q.push(Step(N,0));
	visited[N]=1;
	while(!q.empty()){
		Step s=q.front();
		if(s.x==K){
			printf("%d",s.steps);
			return 0;
		}else{
			if(s.x-1>=0&&!visited[s.x-1]){
				q.push(Step(s.x-1,s.steps+1));
				visited[s.x-1]=1;
			}
			if(s.x+1>=0&&!visited[s.x+1]){
				q.push(Step(s.x+1,s.steps+1));
				visited[s.x+1]=1;
			}
			if(s.x*2<=MAXN&&!visited[s.x*2]){
				q.push(Step(s.x*2,s.steps+1));
				visited[s.x*2]=1;
			}
			q.pop();
		}
	}
	return 0;
}
