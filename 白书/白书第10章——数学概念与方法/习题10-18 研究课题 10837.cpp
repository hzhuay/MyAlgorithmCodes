//查询必为偶数，答案必为奇数 
#include<cstdio>
#include<cmath>
#include<cstring> 
const int maxn=200000000;
const int maxm=100000000;
const int pLimit=14143;
bool vis[pLimit+5];
int prime[pLimit+5],pNum=0,rm;
int ans[maxm+5];
void build_prime(){
	int m=sqrt(pLimit+0.5);
	for(int i=2;i<=m;i++)
		if(!vis[i])
			for(int j=i*i;j<=pLimit;j+=i)
				vis[j]=true;
	for(int i=2;i<=pLimit;i++)if(!vis[i])prime[pNum++]=i;
	printf("%d %d\n",pNum,prime[pNum-1]);
}
int cal(int n){
	int ans=n;
	for(int i=0;i<pNum;i++){
		if(n%prime[i]==0){
			ans=ans/prime[i]*(prime[i]-1);
			while(n%prime[i]==0)n/=prime[i];
		}
	}
	if(n!=1)ans=ans/n*(n-1);
	return ans;
}
int main(){
	int m,kase=1,p=1,tmp;
	build_prime();
	ans[0]=1;
	for(int i=3;i<1000;i+=2){//i为可能的答案 
		if(prime[p]==i){
			p++;
			ans[(i-1)/2]=i;
			continue; 
		}
		tmp=cal(i)/2;
		if(ans[tmp]==0)
			ans[tmp]=i;
	}
	puts("ok");
	for(int i=1;i<=1000;i++)
		if(i%2==1&&i!=1)printf("%d 0\n",i);
		else printf("%d %d\n",i,ans[i/2]);
	/*
	while(scanf("%d",&m),m){
		if(m%2==1&&m!=1)printf("Case %d: %d 0\n",kase++,m);
		else printf("Case %d: %d %d\n",kase++,m,ans[m/2]);
	}
	*/
	return 0;
} 
