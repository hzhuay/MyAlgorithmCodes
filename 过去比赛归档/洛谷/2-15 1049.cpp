#include<cstdio>
#include<algorithm>
using namespace std;
int v[35],dp[20005];//dp[i]的定义：当容积为i时所能装的最大体积 
int main(){
	int V,n;
	scanf("%d%d",&V,&n);
	for(int i=0;i<n;i++)scanf("%d",&v[i]);
	for(int i=0;i<n;i++){
		for(int j=V;j>=v[i];j--){
			dp[j]=max(dp[j-v[i]]+v[i],dp[j]);
		}
	}
	printf("%d",V-dp[V]);
	return 0;
}
