#include<cstdio>
long long pow[15]={1},ans;
int main(){
	int k,N,i=0;
	scanf("%d%d",&k,&N);
	for(int i=1;i<12;i++)pow[i]=pow[i-1]*k;
	while(N){
		if(N&1)ans+=pow[i];
		N=N>>1;
		i++;
	}
	printf("%lld",ans);
	return 0;
}
