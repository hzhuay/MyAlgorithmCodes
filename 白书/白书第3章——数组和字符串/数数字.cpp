#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int ans[10];
int main(){
	int n,x,t,j,y;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		for(t=0;t<10;t++)ans[t]=0;
		for(j=1;j<=x;j++){
			y=j;
			while(y>0){
				ans[y%10]++;
				y=y/10;
			}
		}
		for(t=0;t<9;t++)printf("%d ",ans[t]);
		printf("%d",ans[9]);
		puts("");
	}
	return 0;
}
