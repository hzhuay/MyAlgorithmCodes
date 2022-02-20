#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1005;
int n,d[maxn];
bool G[maxn][maxn];
struct Rectangle{
	int w,h;
}rec[maxn];
int dp(int i){
	int &ans=d[i];//可以用引用来简洁代码 
	if(ans>0)return ans;
	ans=1;
	for(int j=0;j<n;j++)
		if(G[i][j])ans=max(ans,dp(j)+1);
	return ans;
}
void build_Graph(){
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(rec[i].w>rec[j].w&&rec[i].h>rec[j].h)
				G[i][j]=1;//i可以包含j 	
}
void print_ans(int i){//如果有多解，矩形编号的字典序尽量小 
	printf("%d ",i+1);//编号从1开始
	for(int j=0;j<n;j++)
		if(G[i][j]&&d[i]==d[j]+1){
			print_ans(j);
			break;
		}
}
int main(){
	int kase;
	scanf("%d",&kase);
	while(kase--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d%d",&rec[i].w,&rec[i].h);
			if(rec[i].h>rec[i].w)swap(rec[i].h,rec[i].w);
		}
		build_Graph();
		int ans=0;
		for(int i=1;i<n;i++)
			if(d[ans]<dp(i))ans=i;
		printf("%d\n",d[ans]);
		print_ans(ans);
		memset(d,0,sizeof(d));
		memset(G,0,sizeof(G));
		memset(rec,0,sizeof(rec));
	}
	return 0;
}
