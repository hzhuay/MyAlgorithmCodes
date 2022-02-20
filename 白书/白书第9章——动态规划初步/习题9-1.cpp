#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
int R,C,h[105][105],ans[105][105];
int mx[5]={1,0,-1,0},my[5]={0,1,0,-1};
struct Step{
	int x;
	int y;
	Step(int xx,int yy):x(xx),y(yy){}
};
queue<Step>q;
void bfs(){
	while(!q.empty()){
		Step s=q.front();
		for(int k=0;k<4;k++){
			if(h[s.x][s.y]<h[s.x+mx[k]][s.y+my[k]]){
				q.push(Step(s.x+mx[k],s.y+my[k]));
				ans[s.x+mx[k]][s.y+my[k]]=max(ans[s.x][s.y]+1,ans[s.x+mx[k]][s.y+my[k]]);
			}
		}
		q.pop();
	}
}
int main(){
	int kase;
	char name[100];
	scanf("%d",&kase);
	while(kase--){
		scanf("%s%d%d",name,&R,&C);
		int max=0;
		for(int i=1;i<=R;i++)
			for(int j=1;j<=C;j++){
				scanf("%d",&h[i][j]);
				ans[i][j]=1;
			}
			
		for(int i=1;i<=R;i++)
			for(int j=1;j<=C;j++){
					q.push(Step(i,j));
					bfs();
				}
		max=0;
		for(int i=1;i<=R;i++)
			for(int j=1;j<=C;j++)
				if(max<ans[i][j])max=ans[i][j];
		/*
		for(int i=1;i<=R;i++){
			for(int j=1;j<=C;j++)
				printf("%d ",ans[i][j]);
			puts("");
		}	
		*/
		printf("%s: %d\n",name,max);
		memset(h,0,sizeof(h));
		memset(ans,0,sizeof(ans));
	}
	return 0;
}
