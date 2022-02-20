#include<cstdio>
#include<iostream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
using namespace std;
int map[10][10],stair[10]={0,7,13,18,22,25,27};
int mr[5]={1,0,-1,0},mc[5]={0,1,0,-1},ans[10][10],num;
bool mark[30];
inline int f(int x,int y){return stair[x]-x+y+1;}//x <= y
inline bool isVisited(int r,int c){return r>0&&r<8&&c>0&&c<9&&!ans[r][c];}
void dfs(int r,int c,int cnt){
	if(cnt==28){
		num++;
		for(int i=1;i<=7;i++){
			for(int j=1;j<=8;j++)
				printf("%4d",ans[i][j]);
			puts("");
		}
		printf("\n\n");
		return;
	}
	if(ans[r][c]){
		if(c==8)dfs(r+1,1,cnt);
		else dfs(r,c+1,cnt);
		return;
	}
	for(int i=0;i<4;i++){
		int tmpr=r+mr[i],tmpc=c+mc[i];
		int pip1=min(map[tmpr][tmpc],map[r][c]);
		int pip2=max(map[tmpr][tmpc],map[r][c]);
		int bone=f(pip1,pip2);
		if(!isVisited(tmpr,tmpc)||mark[bone])continue;
		mark[bone]=1;
		ans[tmpr][tmpc]=ans[r][c]=bone;
		if(c==8)dfs(r+1,1,cnt+1);
		else dfs(r,c+1,cnt+1);
		mark[bone]=0;
		ans[tmpr][tmpc]=ans[r][c]=0;
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	int kase=1,count_line=1;
	string line;
	while(getline(cin,line)){
		stringstream ss(line);
		for(int j=1;j<=8;j++){
			ss>>map[count_line][j];
		}
		if(count_line==7){
			if(kase>=2)printf("\n\n\n");
			printf("Layout #%d:\n\n",kase);
			for(int i=1;i<=7;i++){
				for(int j=1;j<=8;j++)
					printf("%4d",map[i][j]);
				puts("");
			}
			printf("\nMaps resulting from layout #%d are:\n\n",kase);
			num=0;
			dfs(1,1,0);
			printf("\nThere are %d solution(s) for layout #%d.\n",num,kase);
			
			count_line=1;
			kase++;
			memset(mark,0,sizeof(mark));
			memset(ans,0,sizeof(ans));
		}else count_line++;
	}
	return 0;
}
