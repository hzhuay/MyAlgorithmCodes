#include<cstdio>
int a[105],b[105];
int main(){
	int n,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<n;i++){
		int rank=0;
		for(int j=0;j<n;j++){
			if(a[i]>a[j])rank++;
		}
		b[rank]=a[i];
	}
	for(int i=0;i<n;i++)if(b[i]!=0)a[ans++]=b[i];
	printf("%d\n",ans);
	for(int i=0;i<ans;i++)printf("%d ",a[i]);
	return 0;
}
