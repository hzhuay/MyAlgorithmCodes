#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=2005;
int T[maxn][maxn],dp[maxn][maxn],ans[maxn];
int main(){
	int tmp,n,N,H,D;
	scanf("%d%d%d",&N,&H,&D);
	for(int i=0;i<N;i++){
		scanf("%d",&n);
		for(int j=0;j<n;j++){
			scanf("%d",&tmp);
			T[i][tmp]++;
		}
	}
	for(int j=H;j>0;j--){
		for(int i=0;i<N;i++){
			dp[i][j]=max(ans[j+D],dp[i][j+1])+T[i][j];
			if(ans[j]<dp[i][j])ans[j]=dp[i][j];
		}
	}
	printf("%d\n",ans[1]);
	return 0;
}
