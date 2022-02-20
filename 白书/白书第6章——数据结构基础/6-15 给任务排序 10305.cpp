#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=105;
int c[maxn],G[maxn][maxn];
int topo[maxn],t,n;
bool dfs(int u){
	c[u]=-1;
	for(int v=1;v<=n;v++)
		if(G[u][v]){
			if(c[v]<0)
				return false;//存在有向环 
			else if(!c[v]&&!dfs(v))
				return false;
		}
	c[u]=1;topo[--t]=u;
	return true;
}
bool toposort(){
	t=n;
	memset(c,0,sizeof(c));
	for(int i=1;i<=n;i++)
		if(!c[i]&&!dfs(i))return false;
	return true;
}
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int m;
	while(scanf("%d%d",&n,&m)&&n+m){
		memset(G,0,sizeof(G));
		memset(topo,0,sizeof(topo));
		for(int i=0,x,y;i<m;i++){
			scanf("%d%d",&x,&y);
			G[x][y]=1;
		}
		if(toposort()){
			int i;
			for(i=0;i<n-1;i++)
				printf("%d ",topo[i]);
			printf("%d\n",topo[i]);
		}
	}
}
