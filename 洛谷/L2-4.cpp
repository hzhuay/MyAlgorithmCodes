#include<cstdio>
#include<vector>
#include<queue>
#include<set>
#include<cstring>
using namespace std;
const int maxn=505;
vector<int>edge[maxn];
queue<int>Q;
set<int>s;
bool vis[maxn];
int mark[maxn];
bool bfs(int st){
	int now,next;
	Q.push(st);
	while(!Q.empty()){
		now=Q.front();Q.pop();
		if(vis[now])continue;
		else vis[now]=true;
		for(int i=0;i<(int)edge[now].size();i++){//枚举所有与当前点相连的点，染色或检查 
			next=edge[now][i];
			if(!vis[next]){
				if(mark[next]==mark[now])return false;//检查 
				Q.push(next);
			}
		}
	}
	return true;//该连通分量染色成功 
}
int main(){
	int V,E,K,N;
	scanf("%d%d%d",&V,&E,&K);
	while(E--){
		int a,b;
		scanf("%d%d",&a,&b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	scanf("%d",&N);
	while(N--){
		for(int i=1;i<=V;i++){
			scanf("%d",&mark[i]);
			s.insert(mark[i]);
		}
		if(s.size()>K)puts("No");
		else if(bfs(1))puts("Yes");
		else puts("No");
		memset(mark,0,sizeof(mark));
		memset(vis,0,sizeof(vis));
		s.clear();
		while(!Q.empty())Q.pop();
	}
	return 0;
}
