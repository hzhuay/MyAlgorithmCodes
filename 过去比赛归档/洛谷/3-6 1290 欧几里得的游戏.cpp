//一直死磕，谁先拿到选择权谁赢 
#include<bits/stdc++.h>
using namespace std;
#define LL long long
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		LL a,b;
		scanf("%lld%lld",&a,&b);
		if(a<b)swap(a,b);
		if(a>2*b||b==0)puts("Stan wins");
		else{
			bool flag=true;
			while(a/b==1&&a%b!=0){
				a%=b;
				if(a<b)swap(a,b);
				flag=!flag;
			}
			if(flag)puts("Stan wins");
			else puts("Ollie wins");
		}
	}
	return 0;
}
