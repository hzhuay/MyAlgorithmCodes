#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+5;
struct node{
	int v,i,nx,ii;
}a[maxn],b[maxn];
inline bool cmp1(node a,node b){
	if(a.v!=b.v)return a.v<b.v;
	else return a.ii<b.ii;
}
inline bool cmp2(node a,node b){return a.i<b.i;}
int main(){
	int n,s,k=0;
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++){
		a[i].i=i;
		scanf("%d%d",&a[i].v,&a[i].nx);
	}
	for(int i=s;a[i].i!=0;i=a[i].nx){
		b[++k]=a[i];
		b[k].ii=k;
	}
	sort(b+1,b+n+1,cmp1);
	printf("%d\n",b[1].i);
	s=b[1].i;
	for(int i=1;i<n;i++)b[i].nx=b[i+1].i;
	b[n].nx=0;
	sort(b+1,b+n+1,cmp2);
	for(int i=1;i<=n;i++)printf("%d\n",b[i].nx);
	return 0;
}
