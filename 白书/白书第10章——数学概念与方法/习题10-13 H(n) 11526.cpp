#include<cstdio>
#include<cmath> 
int main(){
	int kase,n;
	scanf("%d",&kase);
	while(kase--){
		scanf("%d",&n);
		int R=sqrt(n+0.5),L,U;
		long long ans=0;
		for(int i=1;i<=R;i++){
			ans+=n/i;
			L=n/(i+1);
			U=n/i;
			ans+=(U-L)*i;
		}
		if(R*R+R>n)ans-=R;
		printf("%lld\n",ans);
	}
	return 0;
} 
