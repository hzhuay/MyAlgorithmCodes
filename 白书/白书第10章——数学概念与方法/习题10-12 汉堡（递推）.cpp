#include<cstdio>
const int maxn=100005;
double p[maxn];
int main(){
	p[2]=0;
	for(int i=2;i<maxn;i++)
		p[i+2]=p[i]*(i-1)/i+1.0/i;
	int kase;
	scanf("%d",&kase);
	while(kase--){
		int n;
		scanf("%d",&n);
		printf("%.4f\n",p[n]);
	}
	return 0; 
}
