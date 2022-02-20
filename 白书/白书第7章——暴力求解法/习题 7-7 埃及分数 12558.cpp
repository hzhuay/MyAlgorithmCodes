#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<set>
using namespace std;
long long v[10000],ans[10000];
int maxd;
set<int>u;
int gcd(long long a,long long b){return b==0?a:gcd(b,a%b);}
int get_first(int a,int b){return b/a+1;}
bool better(int d){
	for(int i=d;i>=0;i--)
		if(v[i]!=ans[i])
			return ans[i]==-1||v[i]<ans[i];
	return 0;
}
bool dfs(int d,int from,long long aa,long long bb){
	if(d==maxd){
		if(bb%aa)return false;
		if(u.find(bb/aa)!=u.end())return false;
		v[d]=bb/aa;
		if(better(d))memcpy(ans,v,sizeof(long long)*(d+1));
		return true;
	}
	bool ok=false;
	from=max(from,get_first(aa,bb));
	for(int i=from;;i++){
		//剪枝:减去不可能的层数
		if(bb*(maxd+1-d)<=i*aa)break;
		if(u.find(i)!=u.end())continue;
		v[d]=i;
		//计算aa/bb-1/i,设结果为a2/b2
		long long b2=bb*i;
		long long a2=aa*i-bb;
		long long g=gcd(a2,b2);
		if(dfs(d+1,i+1,a2/g,b2/g))ok=true;
	}
	return ok;
}
int main(){
	int a,b,kase=1,k;
	scanf("%d",&kase);
	for(int T=1;T<=kase;T++){
		bool ok=1;
		scanf("%d%d%d",&a,&b,&k);
		while(k--){
			int tmp;
			scanf("%d",&tmp);
			u.insert(tmp);
		}
		for(maxd=1;;maxd++){
			memset(ans,-1,sizeof(ans));
			if(dfs(0,get_first(a,b),a,b)){ok=0;break;}
		}
		printf("Case %d: %d/%d=",T,a,b);
		for(int i=0;i<=maxd;i++)
			printf("1/%lld%c",ans[i],"+\n"[i==maxd]);
		memset(v,0,sizeof(v));
		u.clear();
	}
	return 0;
}

