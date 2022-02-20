#include<cstdio>
int h[100005];
int main(){
	int ans=0,n,tmp=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&h[i]);
	for(int i=0;i<n;i++){
		if(h[i]>tmp)ans+=h[i]-tmp;
		tmp=h[i];
	}
	printf("%d",ans);
	return 0;
}
