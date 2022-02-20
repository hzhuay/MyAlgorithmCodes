#include<bits/stdc++.h>
using namespace std;
const int maxl=50*65;
int a[70],sum,M,n;
bool vis[70],mark;
bool cmp(int x,int y){return x>y;}
void dfs(int ans,int s,int goal,int cur){
	if(s*goal==sum){
		printf("%d",goal);
		exit(0);
	}
	if(ans==goal){
		dfs(0,s+1,goal,1);
		return;
	}
	if(goal-ans<a[n-1])return;
	for(int i=cur;i<n;i++){
		if(!vis[i]&&ans+a[i]<=goal){
			vis[i]=true;
			dfs(ans+a[i],s,goal,i+1);
			vis[i]=false;
			if(ans+a[i]==goal||ans==0)break;
			while(a[i]==a[i+1])i++;
		}
	}
}
int main(){
	int tmpn,tmp;
	scanf("%d",&tmpn);
	for(int i=0;i<tmpn;i++){
		scanf("%d",&tmp);
		if(tmp<=50){
			a[n++]=tmp;
			M=max(M,tmp);
			sum+=tmp;
		}
	}
	sort(a,a+n,cmp);
	for(int i=M;i<=sum/2;i++){
		if(sum%i==0){
			dfs(0,0,i,0);
		}
	}
	printf("%d",sum);
}
