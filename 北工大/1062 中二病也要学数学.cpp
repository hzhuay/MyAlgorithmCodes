#include<cstdio>
double a[10];
int main(){
	//freopen("in.txt","r",stdin);
	int kase;
	double tmp;
	bool flag,mark;
	scanf("%d",&kase);
	while(kase--){
		flag=false;
		mark=false;
		for(int i=9;i>=0;i--)scanf("%lf",&a[i]);
		for(int i=9;i>=3;i--){
			if(a[i]!=0){
				tmp=i*a[i];
				mark=true;
				if(!flag)flag=true;
				else printf("+");
				if(tmp==1.000)printf("x^%d",i-1);
				else printf("%.3fx^%d",tmp,i-1);
			}
		}
		if(a[2]!=0){
			tmp=a[2]*2;
			mark=true;
			if(!flag)flag=true;
			else printf("+");
			if(tmp==1.000)printf("x");
			else printf("%.3fx",tmp);
		}
		if(a[1]!=0){
			mark=true;
			if(!flag)flag=true;
			else printf("+");
			printf("%.3f",a[1]);
		}
		if(!mark)printf("0.000");
		puts("");
	}
	return 0;
}
