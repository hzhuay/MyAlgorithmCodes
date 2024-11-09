#include<iostream>
#define M 100000000
using namespace std;
int ans[M];
int main(){
	int a,b,c,le,i,kase=1;
	while(scanf("%d %d %d",&a,&b,&c)&&a!=0&&b!=0&&c!=0){
		ans[0]=a/b;
		le=(a%b)*10;
		for(i=1;i<=100;i++){
			ans[i]=le/b;
			le=(le%b)*10;
		}
		printf("Case %d: ",kase);
		kase++;
		for(i=0;i<=c;i++)printf("%d",ans[i]);
		puts("");
	}
	return 0;
}

