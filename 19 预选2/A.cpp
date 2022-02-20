#include<cstdio>
int main(){
	int n;
	while(scanf("%d",&n)==1){
		int ans=0;
		if(n==0)ans++;
		while(n){
			if(n%2==0)ans++;
			n/=10;
		}
		if(ans%2==1)printf("ok\n");
		else printf("bu ok\n");
	}
	return 0;
}
