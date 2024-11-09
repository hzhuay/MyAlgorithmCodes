#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int maxn=200000+5;
int edge[maxn],len[maxn];
bool vis[maxn];
queue<int>q;
vector<int>v;
int main(){
	int n,ans=maxn;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&edge[i]);
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			q.push(i);
			int tmp=0;
			while(!q.empty()){
				int now=q.front();q.pop();
				if(vis[edge[now]])break;
				tmp++;
				if(len[edge[now]]==0){//是第一次访问 
					len[edge[now]]=tmp;
					v.push_back(edge[now]);
					q.push(edge[now]);
				}else{//第二次访问，已形成环  
					ans=min(ans,tmp-len[edge[now]]);
					break;
				}
			}
			for(int j=0;j<(int)v.size();j++)vis[v[j]]=true;
			v.clear();
		}
	printf("%d",ans);
	return 0;
} 
