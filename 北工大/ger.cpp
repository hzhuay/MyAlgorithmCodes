#include<cstdio>
#include<cstdlib>
#include<ctime>
int main(){
	freopen("in.txt","w",stdout);
	printf("1000000\n");
	srand(time(NULL));
	for(int i=0;i<1000000;i++){
		printf("9999973 ");
	}
	printf("\n50000\n");
	for(int i=0;i<50000;i++){
		int a=rand();
		int b=rand();
		if(a<b)printf("%d %d\n",a,b);
		else printf("%d %d\n",b,a);
	}
	return 0;
}
