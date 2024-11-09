#include<iostream>
#define M 105 
using namespace std;
int N[M],dp[M];
int it(int n){
	if(dp[n]>=0)return dp[n];
	else return dp[n]=it(n-2)+it(n-1)+it(n-3);
}
int main(){
	int i,j=1;
	while(cin>>N[j++]);
	for(i=1;i<35;i++)
		dp[i]=-1;
	dp[1]=1;
	dp[2]=2;
	dp[3]=4;
	for(i=1;i<35;i++)
		if(N[i])cout<<it(N[i])<<endl;
	return 0;
}

