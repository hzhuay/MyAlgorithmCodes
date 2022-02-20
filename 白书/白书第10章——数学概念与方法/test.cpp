#include<cstdio>
const int maxn=8000;
long long C[maxn+5][maxn/2+5];
long long f(long long x){return x==0?1:x*f(x-1);}
int main(){
	for(int i=1;i<=maxn;i++){
		int U=i,L=1;
		C[i][0]=1;
		for(int j=1;j<=i/2;j++){
			C[i][j]=C[i][j-1]*U--/L++;
			if(C[i][j]<0)break;
		} 
			
	}
	
	for(int i=1;i<=maxn;i++){
		for(int j=1;j<=i/2;j++)
			if(C[i][j]<=1000000000000000&&C[i][j]>0)printf("%lld ",C[i][j]);
		puts("");
	}
	
	return 0;
}
