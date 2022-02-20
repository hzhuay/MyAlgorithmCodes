#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int fin,nfb,blk[55];
int mx[]={1,0,0,-1};
int my[]={0,1,-1,0};
char dec[]="ensw";
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
			if(str[s.x+mx[k]][s.y+my[k]]=='T'){
				printf("%d",s.steps+1);
				return;
			}
			else if(str[s.x+mx[k]][s.y+my[k]]=='.'&&!visited[s.x+mx[k]][s.y+my[k]]){
				q.push(Step(s.x+mx[k],s.y+my[k],s.steps+1));
				visited[s.x+mx[k]][s.y+my[k]]=1;
			}
		}
		q.pop();
	}
}
int main(){
	int kase;
	scanf("%d",&kase);
	while(kase--){
		scanf("%d%d",&fin,&nfb);
		for(int i=0;i<nfb;i++)
			scanf("%d",&blk[i]);
		bfs(); 
		
	}
	return 0;
}
