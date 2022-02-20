#include<cstdio>
int A[10005];
int main(){
	int n,x;
	scanf("%d%d",&n,&x);
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	int L=0,R=n-1,mid;
	while(L<=R){
		mid=(L+R)/2;
		if(A[mid]==x)break;
		if(A[mid]>x)R=mid-1;
		else L=mid+1;
	}
	if(A[mid]==x)printf("%d\n",mid+1);
	else puts("-1");
	return 0;
} 
