#include<bits/stdc++.h>
long long quick(long long x,long long y,long long P){
	int ans=1;
	if(y==0)return x%P;
	while(y>0){
		if(y&1)ans=ans*x%P;
		y>>=1;
		x=x*x%P;
	}
	return ans;
}
long long pow_mod(long long a,long long n,int m){//ÒªÇón>0 
	if(n==0)return 1;
	long long x=pow_mod(a,n/2,m);
	long long ans=(long long)x*x%m;
	if(n%2==1)ans=ans*a%m;
	return (int)ans;
}
int main(){
	long long b,p,k;
	scanf("%lld%lld%lld",&b,&p,&k);
	printf("%lld^%lld mod %lld=%lld",b,p,k,quick(b,p,k));
//	printf("%lld^%lld mod %lld=%lld",b,p,k,pow_mod(b,p,k));
	return 0;
}
