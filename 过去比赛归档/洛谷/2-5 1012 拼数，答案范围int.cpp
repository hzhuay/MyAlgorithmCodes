#include<cstdio>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;
const int M=25;
int len[M],a[M],p[M]={1},ans,n;
char str[M][20];
bool vis[M];
void dfs(int cur,int dig){
	for(int i=0;i<n;i++){
		if(dig+len[i]<=10&&!vis[i]){
			long long tmp=cur*p[len[i]]+a[i];
			if(tmp<=INT_MAX){
				ans=max((int)tmp,ans);
				vis[i]=true;
				dfs((int)tmp,dig+len[i]);
				vis[i]=false;
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",str[i]);
		len[i]=strlen(str[i]);
		sscanf(str[i],"%d",&a[i]);
	}
	for(int i=1;i<10;i++)
		p[i]=p[i-1]*10;
	dfs(0,0);
	printf("%d",ans);
	return 0;
}
