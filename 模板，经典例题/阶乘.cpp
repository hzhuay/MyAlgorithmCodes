#include<cstdio>
long long f(int x){return x==0?1:x*f(x-1);}
int main(){
	int n;
	while(scanf("%d",&n))
		printf("%lld\n",f(n));
	return 0;
}
