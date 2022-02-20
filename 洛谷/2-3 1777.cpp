#include<cstdio>
int a[100005],b[100005];
void merge(int l,int r){
	if(l>=r)return;
	int i,mid=(l+r)/2,p1=l,p2=mid+1;
	merge(l,mid);
	merge(mid+1,r);
	for(int i=l;i<=r;i++)b[i]=a[i];
	i=l;
	while(p1<=mid&&p2<=r)
		if(b[p1]<b[p2])a[i++]=b[p1++];
		else a[i++]=b[p2++];
	while(p1<=mid)a[i++]=b[p1++];
	while(p2<=r)a[i++]=b[p2++];
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	merge(0,n-1);
	for(int i=0;i<n;i++)printf("%d ",a[i]);
	return 0;
}
