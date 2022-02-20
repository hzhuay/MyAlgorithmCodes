#include<cstdio>
#include<queue>
#include<cstring>
#include<vector> 
#include<algorithm>
using namespace std;
int k,N,n,fr[800],to[800],path[22],ans;
vector<int>rot[22];
bool vis[22];
bool bfs(){
	queue<int>q;
	memset(vis,1,sizeof(vis));
	q.push(1);vis[1]=1;
	while(!q.empty()){
		int s=q.front();
		for(int i=0;i<N;i++){
			if(fr[i]==s){
				if(to[i]==k)return true;
				else if(vis[to[i]]){
					q.push(to[i]);
					vis[to[i]]=0;
				}
			}
			if(to[i]==s){
				if(fr[i]==k)return true;
				else if(vis[fr[i]]){
					q.push(fr[i]);
					vis[fr[i]]=0;
				}
			}
		}
		q.pop();
	}
	return false;
}
void dfs(int rt,int depth){
	if(rt==k){
		path[depth]=rt;
		for(int j=0;j<=depth;j++){
			printf("%d%c",path[j]," \n"[j==depth]);
		}
		ans++;
		return;
	}
	for(int i=0;i<rot[rt].size();i++){
		if(vis[rot[rt][i]]){
			vis[rot[rt][i]]=0;
			path[depth]=rt;
			dfs(rot[rt][i],depth+1);
			vis[rot[rt][i]]=1;
		}
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int kase=1;
	while(scanf("%d",&k)!=EOF){
		printf("CASE %d:\n",kase++); 
		N=0;n=0;
		while(scanf("%d%d",&fr[N],&to[N]),fr[N]!=0){
			n=max(n,fr[N]);
			n=max(n,to[N]);
			N++;
		}
		ans=0;
		if(bfs()||k==1){
			for(int i=0;i<N;i++){
				rot[fr[i]].push_back(to[i]);
				rot[to[i]].push_back(fr[i]);
			}
			for(int i=1;i<=20;i++)sort(rot[i].begin(),rot[i].end());
			/*
			for(int j=1;j<=n;j++){
				printf("%d: ",j);
				for(int i=0;i<rot[j].size();i++){
					printf("%d ",rot[j][i]);
				}
				puts("");
			}
			*/
			memset(vis,1,sizeof(vis));vis[1]=0;
			dfs(1,0);
		}
		printf("There are %d routes from the firestation to streetcorner %d.\n",ans,k);
		
		memset(fr,0,sizeof(fr));
		memset(to,0,sizeof(to));
		memset(rot,0,sizeof(rot));
		memset(path,0,sizeof(path));
	}
	return 0;
}
