#include<cstdio>
#include<cmath> 
const int maxn=1000000;
bool vis[maxn+5];
int n;
void build_prime(){
	int m=sqrt(n+0.5);
	for(int i=2;i<=m;i++)
		if(!vis[i])
			for(int j=i*i;j<=n;j+=i)
				vis[j]=true;
	vis[1]=true;
	//int k=0;
	//for(int i=2;i<=n;i++)if(!vis[i])prime[k++]=i;
	//printf("%d %d\n",k,prime[k-1]); 
}
int main(){
	int kase,l,r;
	scanf("%d%d",&kase,&n);
	build_prime();
	while(kase--){
		scanf("%d%d",&l,&r);
		if(l>n||l<1||r<1||r>n){
			puts("Crossing the line");
			continue;
		}else{
			int ans=0;
			for(int i=l;i<=r;i++)
				if(!vis[i])ans++;
			printf("%d\n",ans);
		}
	}
	return 0;
}
