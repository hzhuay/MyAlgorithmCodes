#include<cstdio>
#include<cstring>
#define mod 1000000007
#define LL long long
struct Mat{
	LL m[5][5];
}e; 
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
	scanf("%d",&T);
	e.m[1][1]=e.m[3][1]=e.m[1][2]=e.m[2][3]=1;
	while(T--){
		scanf("%d",&p);
		Mat ans=pow(e,p-2);
		printf("%lld\n",ans.m[1][1]%mod);
	}
	return 0;
}
