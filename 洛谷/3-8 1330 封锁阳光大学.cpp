#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
const int maxn=10000+5;
vector<int>edge[maxn];
queue<int>Q;
bool vis[maxn],mark[maxn];
int ans;
bool bfs(int st){
	int now,next,cnt=0,num=0;
	Q.push(st);
	while(!Q.empty()){
		now=Q.front();
		Q.pop();
		if(vis[now])continue;
		vis[now]=true;
		if(mark[now])cnt++;num++;
		for(int i=0;i<(int)edge[now].size();i++){//枚举所有与当前点相连的点，染色或检查 
			next=edge[now][i];
			if(vis[next]){//检查 
				if(mark[next]==mark[now])return false;
			}else{//染色 
				mark[next]=!mark[now];
				Q.push(next);
			}
		}
	}
	ans+=min(cnt,num-cnt);
	return true;//该连通分量染色成功 
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	while(m--){
		int a,b;
		scanf("%d%d",&a,&b);
		edge[a].push_back(b);
		edge[b].push_back(a);//这里决定是有向图还是无向图 
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			if(!bfs(i)){
				printf("Impossible");
				return 0;
			}
		}
	printf("%d",ans);
	return 0;
}
