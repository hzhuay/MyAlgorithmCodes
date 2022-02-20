#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
vector<int>v[maxn];
queue<int>q;
int ans[maxn]={0,1},step[maxn]{0,1};
bool vis[maxn];
void bfs(){
	while(!q.empty()){
		int now=q.front();q.pop();
		for(int i=0;i<(int)v[now].size();i++){
			int tmp=v[now][i];
			if(step[tmp]==0){
				step[tmp]=step[now]+1;
				ans[tmp]+=ans[now];
				ans[tmp]%=100003;
				if(!vis[tmp])vis[tmp]=true,q.push(tmp);
			}else if(step[tmp]==step[now]+1){	
				ans[tmp]+=ans[now];
				ans[tmp]%=100003;
				if(!vis[tmp])vis[tmp]=true,q.push(tmp);
			}
		}
	}
}
int main(){
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	q.push(1);
	bfs();
	for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
	return 0;
}
