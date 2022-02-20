#include<cstdio>
int main(){
	freopen("in.txt","w",stdout);
	int n=10000;
	printf("1\n%d\n",n);
	for(int i=n;i>0;i--){
		printf("%d ",i);
	}
	return 0;
} 
