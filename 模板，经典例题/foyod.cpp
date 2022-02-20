#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=1000000000; 
const int maxn=1005;
int inq[maxn],cnt[maxn],d[maxn][maxn];
int n;
bool Floyd(){//求每两点间的最短路 
	memset(d,0x3f,sizeof(d));
	for(int i=0;i<n-1;i++)d[i][i]=0;
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(d[i][j]<INF&&d[k][j]<INF)
					d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
int main(){
	scanf("%d",&n);
	return 0;
}
