#include<cstdio>
double p[50005]={-1},ans;
double backtrack(int x,int y,double tmpp){
	if(x<0||y<0)return 0;
	if(x==1&&y==1)return tmpp;
	return backtrack(x-2,y,tmpp*0.25)+backtrack(x,y-2,tmpp*0.25)+backtrack(x-1,y-1,tmpp*0.5);
}
int main(){
	//freopen("in.txt","r",stdin);
	int kase,n;
	scanf("%d",&kase);
	while(kase--){
		scanf("%d",&n);
		printf("%.4f\n",1-backtrack(n/2,n/2,1));
	}
	return 0;
}
