#include<bits/stdc++.h>
using namespace std;
int n,sum,C[15][15],ans[15];
bool vis[15],flag=false;
void dfs(int p,int re){
	if(p>n){
		if(re==0){
			for(int i=1;i<=n;i++)printf("%d%c",ans[i]," \n"[i==n]);
			flag=true;
		}
		return;
	}
	for(int i=1;i*C[n][p]<=re&&i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			ans[p]=i;
			dfs(p+1,re-i*C[n][p]);
			if(flag)return;
			vis[i]=false;
		}
	}
}
int main(){
	scanf("%d%d",&n,&sum);
	C[1][1]=1;
	for(int i=2;i<=12;i++)
		for(int j=1;j<=i;j++)
			C[i][j]=C[i-1][j-1]+C[i-1][j];
	dfs(1,sum);
	return 0;
}
