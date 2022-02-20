#include<cstdio>
#include<algorithm>
using namespace std;
const int INF=1000000000;
const int maxn=100+5;
int a[maxn][maxn],d[maxn][maxn],Next[maxn][maxn];
int main(){
	int n,m;
	while(scanf("%d%d",&m,&n)==2&&m){
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&a[i][j]);
	
		int ans=INF,first=0;
		for(int i=0;i<m;i++)d[i][0]=a[i][0];
		for(int j=1;j<n;j++){//正推
			for(int i=0;i<m;i++){
				int rows[3]={i,i-1,i+1};
				if(i==0)rows[1]=m-1;//出上界 
				if(i==m-1)rows[2]=0;//出下界 
				sort(rows,rows+3);
				d[i][j]=INF;
				for(int k=0;k<3;k++){
					int tmp=d[rows[k]][j-1]+a[i][j];
					if(tmp<d[i][j]){
						d[i][j]=tmp;
						Next[i][j]=rows[k];
					}
				}
				
				if(j==n-1&&d[i][j]<ans){
					ans=d[i][j];
					first=i;
				}
			}
		}
		printf("%d",first+1);
		for(int i=Next[first][n-1],j=n-2;j>=0;i=Next[i][j],j--)//答案倒着输出的 
			printf(" %d",i+1);
		printf("\n%d\n",ans); 
	}
	return 0;
} 
