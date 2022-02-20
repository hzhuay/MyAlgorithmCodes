#include<bits/stdc++.h>
int mark[9][9],vis[43049800];
int pow[20]={1};
int three(){
	int k=0,ans=0;
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
			ans+=pow[k++]*mark[i][j];
	return ans;	
}
bool check(){
	if()
	return 0;

}
int dfs(int x){
	x+=(x==1?1:-1);
	
}
int main(){
	for(int i=1;i<=16;i++)pow[i]=pow[i-1]*3;
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	mark[1][a]=1;//ºÚ
	//mark[b][c]=2;//°×
	dfs(1);
	return 0;
}
