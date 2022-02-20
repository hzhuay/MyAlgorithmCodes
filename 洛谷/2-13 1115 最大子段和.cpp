#include<bits/stdc++.h>
int main(){
	int n,tmp,cur=0,ans=INT_MIN;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		cur+=tmp;
		if(ans<cur)ans=cur;
		if(cur<0)cur=0;
	}
	printf("%d",ans);
	return 0;
}
