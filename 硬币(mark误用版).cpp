#include<iostream>
using namespace std;
int a[105],t,n;
bool mark[105],mk[10005];
void dp(int t,int sum){
	if(t<=n){
		dp(++t,sum);
		t--; 
		mark[t]=!mark[t];
		dp(t+1,sum);
	}else{
		sum=0;
		for(int j=1;j<=n;j++){
			if(mark[j])sum+=a[j];
		}
		mk[sum]=1;
		return;
	}
}
int main(){
	int i;
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	dp(1,0);
	for(int j=1;j<=10000;j++){
		if(mk[j])cout<<j<<" ";
	}
	puts("");
	return 0;
}
