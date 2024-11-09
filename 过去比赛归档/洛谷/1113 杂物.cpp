#include<cstdio>
#include<algorithm>
using namespace std;
int f[10005];
int main(){
	int N,i,l,k,ans=0;
	scanf("%d",&N);
	while(N--){
		scanf("%d%d",&i,&l);
		while(scanf("%d",&k),k){
			f[i]=max(f[i],f[k]);
		}
		f[i]+=l;
		ans=max(f[i],ans);
	}
	printf("%d",ans);
	return 0;
} 
