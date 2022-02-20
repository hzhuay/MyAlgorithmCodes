#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1005;
int n,d[maxn];
bool G[maxn][maxn];
int dp(int i){
	int &ans=d[i];//可以用引用来简洁代码 
	if(ans>0)return ans;
	ans=1;
	for(int j=0;j<n;j++)
		if(G[i][j])ans=max(ans,dp(j)+1);
	return ans;
}
void print_ans(int i){//如果有多解，矩形编号的字典序尽量小
	printf("%d ",i+1);//编号从1开始
	for(int j=0;j<n;j++)
		if(G[i][j]&&d[i]==d[j]+1){
			print_ans(j);
			break;
		}
}
void build_Graph(){}//可能要建立图  
int main(){
	int kase;
	scanf("%d",&kase);
	while(kase--){
		scanf("%d",&n);
		int tmp1,tmp2; 
		for(int i=0;i<n;i++){
			scanf("%d%d",&tmp1,&tmp2);
			G[tmp1][tmp2]=G[tmp2][tmp1]=1;//无向图，边都是双向 
		}
		int ans=0;
		for(int i=1;i<n;i++)
			if(d[ans]<dp(i))ans=i;
		printf("%d\n",d[ans]);
		print_ans(ans);//输出路径 
		memset(d,0,sizeof(d));
		memset(G,0,sizeof(G));
	}
	return 0;
}
