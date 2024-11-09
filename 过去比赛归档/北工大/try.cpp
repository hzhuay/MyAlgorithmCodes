#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+5;
struct node{
	int v,i,nx;
}a[maxn],b[maxn],c[maxn];
int v[maxn];
bool vis[maxn];
inline bool cmp1(node a,node b){return a.v<b.v;}
inline bool cmp2(node a,node b){return a.i<b.i;}
int main(){
	int n,s,k=0;
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++){
		c[i].i=i;
		scanf("%d%d",&c[i].v,&c[i].nx);
		v[i]=c[i].v;
	}
	/*
	for(int i=s;c[i].i!=0;i=ca[i].nx)b[++k]=c[i];
	sort(v+1,v+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(v[i]==b[j].v&&!vis[j]){
				vis[j]=true;
				a[i]=b[j];
				break;
			}
		}
	}
	*/
	for(int i=s;c[i].i!=0;i=c[i].nx)a[++k]=c[i];
	sort(a+1,a+n+1,cmp1);
	
	
	printf("%d\n",a[1].i);
	s=a[1].i;
	for(int i=1;i<n;i++)a[i].nx=a[i+1].i;
	a[n].nx=0;
	sort(a+1,a+n+1,cmp2);
	for(int i=1;i<=n;i++)
		printf("%d\n",a[i].nx);
	return 0;
}
