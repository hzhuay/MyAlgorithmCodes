#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=10005;
int n,x[maxn],d[maxn];
bool vis[maxn];
struct Node{
	int x,d;
	bool operator < (const Node& x)const{return d<x.d;}
}p[maxn];
int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++)
			//scanf("%d %d",&x[i],&d[i]);
			scanf("%d %d",&p[i].x,&p[i].d);
		sort(p,p+n);
		int time=0,i,tmpx=p[0].x;
		vis[tmpx]=1;
		for(i=1;i<n;i++){
			if(vis[p[i].x])continue;
			else if(time+abs(p[i].x-tmpx)<p[i].d){
				time+=abs(p[i].x-tmpx);
				for(int j=min(p[i].x,tmpx);j<=max(p[i].x,tmpx);j++){
					vis[j]=1;
				}
				tmpx=p[i].x;
				//printf("%d %d %d\n",time,cnt,i);
			}else break;
		}
		if(i==n)printf("%d\n",time);
		else puts("No solution");
		memset(p,0,sizeof(p));
		memset(vis,0,sizeof(vis));
	}
	return 0;
}
