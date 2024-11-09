#include<cstdio>
using namespace std;
int fa(int n,int m){
	if(n<1||m<1) return 0;
	if(n==1||m==1)return 1;
	if(n<m)return fa(n,n);
	if(n==m)return fa(n,m-1)+1;
	if(n>m)return fa(n,m-1)+fa(n-m,m);
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	printf("%d\n",fa(n,m)-fa(n,m-1));
	return 0;
}
