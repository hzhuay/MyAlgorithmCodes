#include<cstdio>
#define LL long long
int n,m,a[85][85],pow[85]={1,2,4,8,16,32,64,128,256};
LL ans,res;
void dfs(int row,int l,int r,LL cur){
	if(l>r){
		if(ans<cur)ans=cur;
		return;
	}
	dfs(row,l+1,r,cur+a[row][l]*pow[l+m-r]);
	dfs(row,l,r-1,cur+a[row][r]*pow[l+m-r]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
		ans=0;
		dfs(i,1,m,0);
		res+=ans;
	}
	printf("%lld",res);
	return 0;
}
