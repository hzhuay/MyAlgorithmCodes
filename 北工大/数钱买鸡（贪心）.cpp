#include<cstdio>
int p[10050]={0,3,6,1,4,1};
int min(int a,int b,int c){
	if(a>b)a=b;
	if(a>c)a=c;
	return a;
}
int main(){
	int kase,n;
	scanf("%d",&kase);
	for(int i=6;i<=10000;i++){
		p[i]=min(p[i-5]+1,p[i-3]+1,p[i-1]+3);
	}
	while(kase--){
		scanf("%d",&n);
		printf("%d\n",p[n]);
	}
	return 0;
}
