#include<cstdio>
int main(){
	int x,tmp;
	long long ans=0;
	scanf("%d",&x);
	for(int i=0;i<x;i++){
		scanf("%d",&tmp);
		ans+=tmp;
	}
	printf("%lld",ans);
	return 0;
}
