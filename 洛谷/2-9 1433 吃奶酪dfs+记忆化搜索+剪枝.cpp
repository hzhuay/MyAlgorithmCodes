#include<bits/stdc++.h>
using namespace std;
double x[20],y[20],d[20][20],ans=1e11;
int n;
bool vis[20];
void dfs(int p,double cur,int cnt){
	if(cur>ans)return;//¼ôÖ¦ 
	if(cnt==n){
		ans=min(ans,cur);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			dfs(i,cur+d[p][i],cnt+1);
			vis[i]=false;
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lf %lf",x+i,y+i);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			d[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
	dfs(0,0,0);
	printf("%.2f",ans);
	return 0;
}
