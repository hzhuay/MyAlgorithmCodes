#include<cstdio>
int main(){
	int L;
	long long d,n,m,b;
	while(scanf("%*d%*c%lld %d",&d,&L)!=EOF){
		m=0,n=0,b=1;
		while(b<d){
			b*=2;
			n++;
		}
		if(b!=d)n--;
		m=n*L;
		printf("%lld %lld\n",n,m);
	}
	return 0;
}
