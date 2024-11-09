#include<cstdio>
#include<vector>
using namespace std;
const int maxn=100000+5;
vector<int>v[maxn];
int pre[maxn],n,l[maxn],dep;
void dfs(int p,int d){
	l[p]=d;
	if(dep<d)dep=d;
	for(int i=0;i<(int)v[p].size();i++){
		dfs(v[p][i],d+1);
	}
}
int main(){
//freopen("out.txt","w",stdout);
	bool flag=false;
	int root;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&pre[i]);
		if(pre[i]==-1)root=i;
		else v[pre[i]].push_back(i);
	}
	dfs(root,1);
	printf("%d\n",dep);
	for(int i=1;i<=n;i++){
		if(l[i]==dep){
			if(flag)printf(" ");
			printf("%d",i);
			flag=true;
		}
	}
	return 0;
}
