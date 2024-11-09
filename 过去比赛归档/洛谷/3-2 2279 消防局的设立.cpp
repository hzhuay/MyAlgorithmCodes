#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1005;
int f[maxn],order[maxn],layer[maxn],dis[maxn];
bool cmp(int i,int j){return layer[i]>layer[j];}//间接排序 
int main(){
	int n,ans=0,fa,now,gf;
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		scanf("%d",&f[i]);//本质上，输入的是每个节点的父节点 
		layer[i]=layer[f[i]]+1;
	}
	for(int i=0;i<=n;i++){
		order[i]=i;
		dis[i]=maxn;
	}
	sort(order+1,order+n+1,cmp);//排序后b数组为节点处理顺序，树的层次遍历 
//从外层向内层遍历 
	for(int i=1;i<=n;i++){
		now=order[i];
		fa=f[now];
		gf=f[f[now]];
		dis[now]=min(dis[now],min(dis[fa]+1,dis[gf]+2));
		if(dis[now]>2){
			dis[gf]=0;
			ans++;
			dis[f[gf]]=min(dis[f[gf]],1);
			dis[f[f[gf]]]=min(dis[f[f[gf]]],2);
		}
	}
	printf("%d",ans);
	return 0;
}
