#include<cstdio>
using namespace std;
double quick(double x,int y){
	double ans=1;
	while(y>0){
		if(y&1)ans*=x;
		y>>=1;
		x*=x;
	}
	return ans;
}
int main(){
	int N,K;
	scanf("%d %d",&N,&K);
	if(N%2==1||N>quick(2,K)||N<2*K)puts("");
	else 
	return 0;
}
