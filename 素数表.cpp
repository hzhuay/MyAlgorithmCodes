#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int prime[470],x[1000005];
int main(){
	int n,m,num=0,l,r;
	for(int i=2;i<3200;i++){
		int tmp=sqrt(i)+1,flag=1;;
		for(int j=2;j<tmp;j++){
			if(i%j==0){
				flag=0;
				break;	
			}
		}
		if(flag)prime[num++]=i;
	}
	for(int i=0;i<num;i++)
		printf("%d\n",prime[i]);
	/*
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&x[i]);
	scanf("%d",&m);
	while(m--){
		scanf("%d%d",&l,&r);
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<452;j++){
				if(prime[j]>r)break;
				if(prime[j]<l)continue;
				if(x[i]%prime[j]==0)ans++;
			}
		}
		printf("%d\n",ans);
	}
	*/
	return 0;
}
 
