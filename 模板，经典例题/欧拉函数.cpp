#include<cstdio>
#include<cmath>
int phi[100000005];
int euler_phi(int n){//小于n并与n互质的整数个数 
	int m=(int)sqrt(n+0.5),ans=n;
	for(int i=2;i<=m;i++)
		if(n%i==0){
			ans=ans/i*(i-1);
			while(n%i==0)n/=i;
		}
	if(n>1)ans=ans/n*(n-1);
	return ans;
}
void phi_table(int n,int* phi){//1-n中所有数的欧拉phi函数值，复杂度O(nloglogn) 
	phi[1]=1;
	for(int i=2;i<=n;i++)
		if(!phi[i]){
			for(int j=i;j<=n;j+=i){
				if(!phi[j])phi[j]=j;
				phi[j]=phi[j]/i*(i-1);
			}
		}
}
int main(){
	phi_table(100000000,phi);
	long long n;
	while(scanf("%d",&n)!=EOF){
		if(n==1)puts("1");
		else printf("%lld\n",euler_phi(n)*n/2);//小于n并与n互质的整数的和 
		printf("%lld\n",phi[n]*n/2);
	}
	return 0;
} 
