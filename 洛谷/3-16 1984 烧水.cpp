#include<cstdio>
int main(){
	int n;
	scanf("%d",&n);
	double cur=420000;
	for(int i=2;i<=n;i++){
		cur=cur/(2*i)*(2*i-1);
	}
	printf("%.2f",cur);
	return 0;
}
