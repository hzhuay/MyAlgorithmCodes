#include<iostream>
#define P 1000000007
#define M 100000005
using namespace std;
int quick(int x,int y){
	int ans=1;
	while(y>0){
		if(y&1)ans=ans*x%P;
		y>>=1;
		x=x*x%P;
	}
	return ans;
}
int main(){
	int x,y;
	cin>>x>>y;
	cout<<quick(x,y);
	return 0;
}
