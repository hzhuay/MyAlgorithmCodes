#include<bits/stdc++.h>
using namespace std;
struct Pair{
    int l,r;
    Pair(int _l=0,int _r=0):l(_l),r(_r){}
    bool operator < (const Pair& x)const{return l<x.l;}
}p[50005],ans;
int main(){
	int n,L,R;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&L,&R);
		p[i]=Pair(L,R);
	}
	sort(p,p+n);
	p[n]=Pair(1000001,1000001);
	ans=p[0];
	for(int i=1;i<=n;i++)
		if(p[i].l<=ans.r)
			ans.r=max(p[i].r,ans.r);
		else{
			printf("%d %d\n",ans.l,ans.r);
			ans=p[i];
		}
	return 0;
}
