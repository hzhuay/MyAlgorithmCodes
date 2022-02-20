#include<cstdio>
#include<cmath> 
using namespace std;
const int pLimit=1000000;
bool vis[pLimit+5];
int prime[79000],pNum=0;
void build_prime(){
	int m=sqrt(pLimit+0.5);
	for(int i=2;i<=m;i++)
		if(!vis[i])
			for(int j=i*i;j<=pLimit;j+=i)
				vis[j]=true;
	for(int i=2;i<=pLimit;i++)if(!vis[i])prime[pNum++]=i;
	//printf("%d %d\n",pNum,prime[pNum-1]); 
}
int main(){
	//freopen("in.txt","r",stdin);
	build_prime();
	int kase;
	long long L,R;
	scanf("%d",&kase);
	while(kase--){
		scanf("%lld%lld",&L,&R);
		int ans=0;
		for(int i=0;i<pNum;i++){
			long long tmp=(long long)prime[i]*prime[i];
			if(tmp>R)break;
			while(tmp<=R){
				if(tmp>=L)ans++;
				tmp*=prime[i];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
