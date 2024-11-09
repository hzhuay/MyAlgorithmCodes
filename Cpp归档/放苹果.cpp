#include<iostream>
using namespace std;
int dp[25][15],n,m,t;
int main(){
    for(int i=1;i<=10;i++){
		dp[0][i]=1;
		dp[i][1]=1;
		dp[1][i]=1;
	}
    for(int i=1;i<=10;i++)
        for(int j=2;j<=11;j++)
            if(i>=j)dp[i][j]=dp[i][j-1]+dp[i-j][j];
            else dp[i][j]=dp[i][j-1];
    cin>>t;
    while(t--){
      cin>>n>>m;     
      cout<<dp[n][m]<<endl;
    }
    return 0;
}
