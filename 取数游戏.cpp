#include<cstdio>
using namespace std;
double C[51][51];
int op(int x){return x%2==0?x/2:x/2+1;}
int main(){
	int n,i,j;
	double ans=0;
	scanf("%d",&n);
	for(i=0;i<=50;i++)C[i][0]=1;
	for(i=1;i<=50;i++)
		for(j=1;j<=i;j++)
			C[i][j]=C[i-1][j-1]+C[i-1][j];
	for(i=0;i<op(n);i++)
		ans+=C[n-i][i+1];
	printf("%.0f",ans+1);
	return 0;
}
