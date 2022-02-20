#include<cstdio>
#define LL long long
LL list[15]={1};
int main(){
	int t,ask;
	for(int i=1;i<=14;i++)list[i]=list[i-1]*i;
	scanf("%d",&t);
	printf("%lld\n",list[t]);
	while(t--){
		scanf("%d",&ask);
		printf("%lld\n",list[ask]);
	}
	return 0;
}
