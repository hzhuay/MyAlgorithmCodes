#include<bits/stdc++.h>
#define LL long long 
using namespace std;
struct Pair{
    LL l,r;
    Pair(LL _l=0,LL _r=0):l(_l),r(_r){}
    bool operator < (const Pair& x)const{return l<x.l;}
}p[500005],cur;
int main(){
	int n;
	LL L,R,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld%lld",&L,&R);
		p[i]=Pair(L,R);
	}
	sort(p,p+n);
	p[n]=Pair(1e17+1,1e17+1);
	cur=p[0];
	for(int i=1;i<=n;i++)
		if(p[i].l<=cur.r)
			cur.r=max(p[i].r,cur.r);
		else{
			ans+=cur.r-cur.l+1;
			cur=p[i];
		}
	printf("%lld",ans);
	return 0;
}
