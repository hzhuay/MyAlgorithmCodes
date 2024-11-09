#include<bits/stdc++.h>
using namespace std;
int m[205],t[205],dp[205][205];
int main(){
	int n,T,M;
	scanf("%d%d%d",&n,&M,&T);
	for(int i=0;i<n;i++)scanf("%d%d",&m[i],&t[i]);
	for(int k=0;k<n;k++){
		for(int i=M;i>-m[k];i--)
			for(int j=T;j>=-t[k];j--)
				dp[i][j]=max(dp[i][j],dp[i+m[k]][j+t[k]]+1);
	}	
	printf("%d",dp[M][T]); 
	return 0;
}
