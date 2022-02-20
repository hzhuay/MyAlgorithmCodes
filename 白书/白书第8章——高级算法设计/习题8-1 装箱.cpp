#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100000+5;
int l[maxn];
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int kase,n,L;
	scanf("%d",&kase);
	while(kase--){
		scanf("%d%d",&n,&L);
		for(int i=0;i<n;i++)
			scanf("%d",&l[i]);
		sort(l,l+n);
		int st=0,ed=n-1,ans=0;
		while(st<=ed){
			if(l[ed]+l[st]<=L)
				st++;
			ed--;
			ans++;
		}
		printf("%d\n%c",ans,"\n"[kase==0]);
		
	}
	return 0;
}

