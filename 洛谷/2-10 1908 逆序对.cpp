#include<cstdio>
const int maxn=500000;
int A[maxn+5],B[maxn+5];
long long ans=0;
void mergeSort(int L,int R){
	if(L>=R)return;
	int i,mid=(L+R)/2,p1=L,p2=mid+1;
	mergeSort(L,mid);
	mergeSort(mid+1,R);
	for(i=L;i<=R;i++)B[i]=A[i];
	for(i=L;p1<=mid&&p2<=R;i++)
		if(B[p1]<=B[p2])A[i]=B[p1++];
		else{
			A[i]=B[p2++];
			ans+=(long long)mid-p1+1;
		}
	while(p1<=mid)A[i++]=B[p1++];
	while(p2<=R)A[i++]=B[p2++];
	return;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&A[i]);
	mergeSort(0,n-1);
	printf("%lld",ans);
	return 0;
} 
