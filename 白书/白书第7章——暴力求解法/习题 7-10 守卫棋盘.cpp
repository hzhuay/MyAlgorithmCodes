#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
bool need[15][15],mark[10][10];
bool vis[4][30];
int maxd,n,m;
bool dfs(int depth,int curr){
	if(depth==maxd){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(need[i][j]&&!vis[0][i]&&!vis[1][j]&&!vis[2][i+j]&&!vis[3][i-j+11])
					return false;
			}	
		}
		return true;
	}
	for(int i=curr;i<n;i++)
		for(int j=0;j<m;j++){
			if(!vis[0][i]||!vis[1][j]||!vis[2][i+j]||!vis[3][i-j+11]){
				bool v0=vis[0][i],v1=vis[1][j],v2=vis[2][i+j],v3=vis[3][i-j+11];
				vis[0][i]=vis[1][j]=vis[2][i+j]=vis[3][i-j+11]=1;
				if(dfs(depth+1,i))return true;
				vis[0][i]=v0;vis[1][j]=v1;vis[2][i+j]=v2;vis[3][i-j+11]=v3;
			}
		}
	return false;
}
int main(){
	//freopen("in.txt","r",stdin);
	int kase=1;
	while(scanf("%d%d",&n,&m)==2&&n!=0){
		for(int i=0;i<n;i++){
			char tmp[15];
			scanf("%s",tmp);
			for(int j=0;j<m;j++){
				if(tmp[j]=='X')need[i][j]=1;
			}
		}
		for(maxd=0;maxd<5;maxd++){
			memset(vis,0,sizeof(vis));
			if(dfs(0,0))break;	
		}
		printf("Case %d: %d\n",kase++,maxd);
		memset(need,0,sizeof(need));
	}
	return 0;
}
