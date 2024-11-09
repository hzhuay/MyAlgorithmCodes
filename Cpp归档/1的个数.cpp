#include<iostream>
using namespace std;
int main(){
	int N,ans=0;
	cin>>N;
	while(N){
		if(N%2==1)ans++;
		N/=2;
	}
	printf("%d",ans);
	return 0;
}
