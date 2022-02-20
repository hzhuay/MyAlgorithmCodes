#include<cstdio>
int a[2005];
int main(){
	int n,t,ans=0;
	scanf("%d%d",&n,&t);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=1;i<n;i++){
		while(a[i]<=a[i-1]){
			a[i]+=t;
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
