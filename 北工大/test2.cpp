#include<cstdio>
int list[15]={1};
int main(){
	for(int i=1;i<14;i++){
		list[i]=list[i-1]*i;
	}
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		printf("%d\n",list[n]);
	}
	return 0;
}
