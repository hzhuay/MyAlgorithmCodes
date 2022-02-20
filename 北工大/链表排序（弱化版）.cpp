#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+5;
struct node{
	int v,i,nx;
}a[maxn],b[maxn];
int v[maxn];
bool vis[maxn];
inline bool cmp1(node a,node b){return a.v<b.v;}
int main(){
	int n,s,k=0;
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++){
		a[i].i=i;
		scanf("%d%d",&a[i].v,&a[i].nx);
		v[i]=a[i].v;
	}
	for(int i=s;a[i].i!=0;i=a[i].nx)b[++k]=a[i];
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
	printf("%d\n",a[1].i);
	s=a[1].i;
	 
	for(int i=1;i<n;i++)a[i].nx=a[i+1].i;
	a[n].nx=0;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[j].i==i)printf("%d\n",a[j].nx);
		}
	}
	return 0;
}
