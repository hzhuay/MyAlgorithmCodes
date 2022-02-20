#include<iostream>
using namespace std;
int main(){
	int n,m,kase=1;
	double ans=0;
	while(scanf("%d %d",&n,&m)&&n!=0&&m!=0){
		while(n<=m){
			ans+=1.0/n/n;
			n++;
		}
		n=m=0;
		printf("Case %d: %.5f\n",kase,ans);
		kase++;
		ans=0;
	}
	
	return 0; 
}
