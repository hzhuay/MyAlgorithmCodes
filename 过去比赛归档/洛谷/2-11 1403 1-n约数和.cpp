#include<bits/stdc++.h>
int main(){
	int n,ans;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)ans+=n/i;
	printf("%d",ans);
	return 0;
}
