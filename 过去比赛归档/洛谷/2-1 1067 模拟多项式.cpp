#include<cstdio>
#include<cmath>
int main(){
	int n,a;
	scanf("%d",&n);
	for(int i=n;i>=0;i--){
		scanf("%d",&a);
		if(a!=0){
			if(i!=n&&a>0)printf("+");
			if(abs(a)!=1||i==0)printf("%d",a);
			if(a==-1&&i)printf("-");
			if(i==1)printf("x");
			if(i>1)printf("x^%d",i);
		}
	}
	return 0;
}
