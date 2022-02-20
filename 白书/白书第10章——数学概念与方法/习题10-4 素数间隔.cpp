#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
bool vis[2000000];
const int maxn=1299709;
int prime[100050];
void build_prime(){
	int m=sqrt(maxn+0.5);
	for(int i=2;i<=m;i++)
		if(!vis[i])
			for(int j=i*i;j<=maxn;j+=i)
				vis[j]=true;
	int k=0;
	for(int i=2;i<=maxn;i++)if(!vis[i])prime[k++]=i;
}
int main(){
	build_prime();
	int n;
	while(scanf("%d",&n),n!=0){
		int l=lower_bound(prime,prime+100000,n)-prime-1;
		if(prime[l+1]==n)puts("0");
		else printf("%d\n",prime[l+1]-prime[l]);
	}	
	return 0;
} 
