#include<cstdio>
#define mod 10007
long long C[1005][1005];
int quick(int x,int y){
	int ans=1;
	if(y==0)return x%mod;
	while(y>0){
		if(y&1)ans=ans*x%mod;
		y>>=1;
		x=x*x%mod;
	}
	return ans;
}
int main(){
	for(int i=0;i<=1000;i++)C[i][0]=1;
	for(int i=1;i<=1000;i++)
		for(int j=1;j<=i;j++){
			C[i][j]=C[i-1][j]+C[i-1][j-1];
			C[i][j]%=mod;
		}
	int a,b,k,n,m,ans=0;	
	scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);	
	ans=C[k][n];
	ans=(ans*quick(a%mod,n))%mod;
	ans=(ans*quick(b%mod,m))%mod;
	printf("%d",ans);
	return 0;
}
