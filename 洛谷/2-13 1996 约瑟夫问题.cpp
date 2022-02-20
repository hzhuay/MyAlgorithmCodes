#include<cstdio>
bool vis[105];
int main(){
	int n,m,cnt=0,tmp;
	scanf("%d%d",&n,&m);
	for(int i=-1;cnt<n;){
		tmp=m;
		while(tmp)
			if(!vis[i=(i+1)%n])tmp--;
		if(!vis[i]){
			vis[i]=true;
			cnt++;
			printf("%d ",i+1);
		}
	} 
	return 0;
}
