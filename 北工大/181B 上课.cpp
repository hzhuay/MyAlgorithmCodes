#include<cstdio>
#include<algorithm>
#define MAX 1005
#define MAXC 1000000005
using namespace std;
int A[MAX],B[MAX],mark[MAX];
int main(){
	int n,m,flag=1;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d %d",&A[i],&B[i]);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(mark[j]<A[i]){
				mark[j]=B[i];
				break;
			}
			if(j==m-1){puts("No");return 0;}
		}
	}
	puts("Yes");
	return 0;
}
