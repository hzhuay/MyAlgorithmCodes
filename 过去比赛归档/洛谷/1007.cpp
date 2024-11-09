#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
//	freopen("in.txt","r",stdin);
	int L,n,tmp=0;
	scanf("%d%d",&L,&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	sort(a,a+n);
	if(n==0)printf("0 0");
	else{
		for(int i=0;i<n;i++)
			tmp=max(tmp,min(a[i],L-a[i]+1));
		printf("%d %d",tmp,max(L-a[0]+1,a[n-1]));
	}
	return 0;
}
