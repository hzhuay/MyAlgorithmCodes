#include<cstdio>
int a[105];
int main(){
	int n,ave=0,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		ave+=a[i];
	}
	ave/=n;
	for(int i=0;i<n;i++)a[i]-=ave;
	for(int i=0;i<n;i++){
		if(a[i]!=0){
			a[i+1]+=a[i];
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
