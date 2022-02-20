#include<cstdio>
int ans[40];
int main(){
	int n,cnt=0;
	scanf("%d",&n);
	while(n){
		ans[cnt++]=(n+1)/2;
		n/=2;
	}
	printf("%d\n",cnt);
	for(int i=cnt-1;i>=0;i--)printf("%d ",ans[i]);
	return 0;
}
