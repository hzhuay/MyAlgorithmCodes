//gcd(F[n],F[m])=F[gcd(n,m)]
#include<cstdio>
#include<cstring>
#define LL long long
#define mod 100000000
using namespace std;
struct Mat{
	LL m[5][5];
}e; 
inline int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int p,T;
Mat Mul(Mat x,Mat y){
	Mat c;
	memset(c.m,0,sizeof(c.m));
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			for(int k=1;k<=3;k++)
				c.m[i][j]+=(x.m[i][k]*y.m[k][j])%mod;
	return c; 
}
Mat pow(Mat x,LL y){
	Mat ans=e;
	if(y<0)return ans;
	while(y){
		if(y&1)ans=Mul(ans,x);  
		x=Mul(x,x);
		y>>=1;
	}
	return ans;
}
int main(){
	int n,m,p;
	scanf("%d%d",&n,&m);
	p=gcd(n,m);
	e.m[1][1]=e.m[1][2]=e.m[2][1]=1;
	Mat ans=pow(e,p-2);
	printf("%lld",ans.m[1][1]%mod);
	return 0;
}
