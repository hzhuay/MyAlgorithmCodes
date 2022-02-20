#include<cstdio>
#include<algorithm>
using namespace std;
struct Grabage{
	int t,f,h;
	bool operator < (const Grabage g) const{
		return t<g.t;
	}
}g[105];
int dp[105][105];//dp[个数][高度]=能量 
int main(){
	int D,G,res=0;
	scanf("%d%d",&D,&G);
	for(int i=1;i<=G;i++){
		scanf("%d%d%d",&g[i].t,&g[i].f,&g[i].h);
	}
	sort(g+1,g+G+1);
	dp[0][0]=10;//初始10能量 
	for(int i=1;i<=G;i++){ 
		for(int j=D-1;j>=0;j--){
			if(dp[i-1][j]==0 || dp[i-1][j]<g[i].t)continue;
			if(dp[i-1][j]>=g[i].t && (j+g[i].h)>=D){
				printf("%d",g[i].t);
				return 0;
			}
			dp[i][j+g[i].h]=max(dp[i][j+g[i].h],dp[i-1][j]);//堆垃圾 
			dp[i][j]=max(dp[i][j],dp[i-1][j]+g[i].f); //吃垃圾 
		}
		res=max(res,dp[i][0]);
	}

	printf("%d",res);
//	for(int i=1;i<=G;i++){
//		printf("%d:",i);
//		for(int j=0;j<=D;j++){
//			printf("%d%c",dp[i][j]," \n"[j==D]);
//		}
//	}
	return 0;
}
