#include<cstdio>
int main(){
	int n,m=1,ans=1;
	scanf("%d",&n);
	int max=n/2;
	while(m<=max)
		if(n%m++==0)
			ans++;
	printf("%d",ans);
	return 0;
}
