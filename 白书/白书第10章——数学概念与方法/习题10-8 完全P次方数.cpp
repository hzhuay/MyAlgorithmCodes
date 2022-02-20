#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
using namespace std;
const int pLimit=46341;
bool vis[pLimit+5];
int prime[5000],pNum=0,R;
int fact[5000],ans[40];
void build_prime(){
	int m=sqrt(pLimit+0.5);
	for(int i=2;i<=m;i++)
		if(!vis[i])
			for(int j=i*i;j<=pLimit;j+=i)
				vis[j]=true;
	for(int i=2;i<=pLimit;i++)if(!vis[i])prime[pNum++]=i;
	//printf("%d %d\n",pNum,prime[pNum-1]);
}
void build_factor(int rm){
	for(int i=0;i<pNum;i++){
		while(rm%prime[i]==0){
			rm/=prime[i];
			fact[i]++;
		}
	}
	if(rm!=1&&rm!=-1)fact[pNum]=1;
}
int main(){
//	freopen("in.txt","r",stdin);
	build_prime();
	int n;
	while(scanf("%d",&n),n!=0){
		build_factor(n);
		int p=0;
		for(int i=1;i<=31;i++){
			bool flag=true;
			for(int j=0;j<=pNum;j++){
				if(fact[j]%i!=0){
					flag=false;
					break;
				}
			}
			if(flag)ans[p++]=i;
		}
		if(n<0){
			for(int i=p-1;i>=0;i--)
				if(ans[i]%2==1){printf("%d\n",ans[i]);break;}
		}else {
			printf("%d\n",ans[p-1]);
		}
		memset(fact,0,sizeof(fact));
		memset(ans,0,sizeof(ans));
	}
	return 0;
}
