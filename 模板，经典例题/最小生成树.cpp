//最小生成树 
#include<bits/stdc++.h>
using namespace std;
const int maxm=200000+5;
const int maxn=5000+5;
int n,m,ans,u[maxm],v[maxm],w[maxm],p[maxn],r[maxm];
int cmp(const int i,const int j){return w[i]<w[j];}//间接排序函数 
int find(int x){return p[x]==x?x:p[x]=find(p[x]);}//并查集的find 
int kruskal(){
	for(int i=0;i<n;i++)p[i]=i;//初始化并查集 
	for(int i=0;i<m;i++)r[i]=i;//初始化边序号 
	sort(r,r+m,cmp);//给边排序
	for(int i=0;i<m;i++){
		int e=r[i];
		int x=find(u[e]);
		int y=find(v[e]);//找出当前边两个端点所在集合编号 
		if(x!=y){//如果不在统一集合，合并 
			ans+=w[e];
			p[x]=y;
		}
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
	if(kruskal())printf("%d",ans);
	else printf("orz");
	return 0;
}
