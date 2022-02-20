#include<bits/stdc++.h>
using namespace std;
int f[1005];
struct Rep{
	int l,r,t;
	bool operator < (const Rep& x)const{return t<x.t;}
}r[100005];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=0;i<m;i++)scanf("%d%d%d",&r[i].l,&r[i].r,&r[i].t);
	sort(r,r+m);
	for(int i=0;i<m;i++){
		int x=find(r[i].r);
		int y=find(r[i].l);
		if(x!=y){f[x]=y;n--;}
		if(n==1){printf("%d",r[i].t);return 0;}	
	}
	printf("-1");
	return 0;
}
