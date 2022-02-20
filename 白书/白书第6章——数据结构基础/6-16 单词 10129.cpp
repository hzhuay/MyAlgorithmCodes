#include<cstdio>
#include<cstring>
#include<queue> 
using namespace std;
int indeg[30],outdeg[30],link[30][30],vis[30],have[30];
char str[1005];
queue<int>q;
void dfs(){
	while(!q.empty()){
		int s=q.front();
		for(int k=0;k<26;k++){
			if(link[s][k]&&!vis[k]){
				q.push(k);
				vis[k]=1;
			}
		}
		q.pop();
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	int kase;
	scanf("%d",&kase);
	while(kase--){
		int n,l,r;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%s",str);
			l=str[0]-'a';r=str[strlen(str)-1]-'a';
			indeg[l]++;
			outdeg[r]++;
			link[l][r]=1;link[r][l]=1;
			have[l]=1;have[r]=1;
		}
		bool flag=true;int cnt=0;
		for(int i=0;i<26;i++){
			if(indeg[i]==outdeg[i]+1||indeg[i]+1==outdeg[i]){
				cnt++;
				if(cnt==3){
					flag=0;
					break;
				}
			}else if(indeg[i]!=outdeg[i]){
				flag=0;
				break;
			}
		}
		if(flag){
			q.push(l);
			dfs();
			for(int i=0;i<26;i++)
				if(have[i]&&!vis[i]){
					flag=0;
					break;
				}
		}
		if(flag)puts("Ordering is possible.");
		else puts("The door cannot be opened.");
		memset(indeg,0,sizeof(indeg));
		memset(outdeg,0,sizeof(outdeg));
		memset(link,0,sizeof(link));
		memset(vis,0,sizeof(vis));
		memset(have,0,sizeof(have));
	}
	return 0;
}
