#include<cstdio>
char ans[1005];
int main(){
	int n,tmp=-1;
	for(int i=2;i<=1000;i++){
		tmp*=-1;
		ans[i]=ans[i-1]*2+tmp;
	}
	while(scanf("%d",&n)!=EOF)printf("%lld\n",ans[n]);
	return 0;
}
