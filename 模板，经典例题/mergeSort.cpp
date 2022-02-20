#include<cstdio>
int A[100]={1,2,9,5,4,3,6,2,1,8},B[100];
void mergeSort(int L,int R){
	if(L>=R)return;
	int i,mid=(L+R)/2,p1=L,p2=mid+1;
	mergeSort(L,mid);
	mergeSort(mid+1,R);
	for(i=L;i<=R;i++)B[i]=A[i];
	for(i=L;p1<=mid&&p2<=R;i++)
		if(B[p1]<B[p2])A[i]=B[p1++];
		else A[i]=B[p2++];
	while(p1<=mid)A[i++]=B[p1++];
	while(p2<=R)A[i++]=B[p2++];
	return;
}
int main(){
	int n=10;
	mergeSort(0,n);
	for(int i=0;i<n;i++)
		printf("%d ",A[i]);
	return 0;
}
