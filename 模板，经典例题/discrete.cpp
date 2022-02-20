#include<cstdio>
#include<algorithm>
#define M 100005
using namespace std;
int A[M],B[M];
int main(){
	int i,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&A[i]);
		B[i-1]=A[i];
	}
	sort(B,B+n);
	int m=unique(B,B+n)-B;
	for(i=1;i<=n;i++)
		A[i]=lower_bound(B,B+m,A[i])-B+1;
//B[A[i]-1]ÕÒÔ­À´Öµ 
	for(i=1;i<=n;i++)
		printf("%d ",A[i]);
	puts("");
	return 0;
}
