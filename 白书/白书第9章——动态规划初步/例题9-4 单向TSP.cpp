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
		for(int j=n-1;j>=0;j--){//逆推 
			for(int i=0;i<m;i++){
				if(j==n-1)d[i][j]=a[i][j];//边界
				else {
					int rows[3]={i,i-1,i+1};
					if(i==0)rows[1]=m-1;//出上界 
					if(i==m-1)rows[2]=0;//出下界 
					sort(rows,rows+3);
					d[i][j]=INF;
					for(int k=0;k<3;k++){
						int tmp=d[rows[k]][j+1]+a[i][j];
						if(tmp<d[i][j]){
							d[i][j]=tmp;
							Next[i][j]=rows[k];
						}
					}
				}
				if(j==0&&d[i][j]<ans){
					ans=d[i][j];
					first=i;
				}
			}
		}
		printf("%d",first+1);
		for(int i=Next[first][0],j=1;j<n;i=Next[i][j],j++)
			printf(" %d",i+1);
		printf("\n%d\n",ans); 
	}
	return 0;
} 
