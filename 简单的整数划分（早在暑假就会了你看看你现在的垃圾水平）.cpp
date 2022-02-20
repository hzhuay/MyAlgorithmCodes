#include<cstdio>
using namespace std;
int b[51];
int f(int n,int m){//把n分成m或小于m个数字相加 
	if(n<1||m<1) return 0;
	if(n==1||m==1)return 1;
	if(n<m)return f(n,n);
	if(n==m)return f(n,m-1)+1;
	if(n>m)return f(n,m-1)+f(n-m,m);
}	
int main(){
	int n;
	for(int i=1;i<=50;i++)b[i]=f(i,i);
	while(scanf("%d",&n)!=EOF)printf("%d\n",b[n]);
	return 0;
}
