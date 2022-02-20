#include<cstdio>
#include<cstring>
#include<cmath> 
bool vis[10000005];
int main(){
	int n,k,t;
	scanf("%d%d",&n,&k);
	int m=sqrt(n+0.5);
	vis[1]=true;
	for(int i=2;i<=m;i++)
		if(!vis[i])
			for(int j=i*i;j<=n;j+=i)
				vis[j]=true;
	while(k--){
		scanf("%d",&t);
		if(vis[t])puts("No");
		else puts("Yes");
	}
	return 0;
}
