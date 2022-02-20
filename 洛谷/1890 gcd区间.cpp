#include<bits/stdc++.h>
inline int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int a[1005],ans[1005][1005];
int main(){
	int n,m,l,r;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		for(int j=0;j<=i;j++){
			ans[j][i]=gcd(ans[j][i-1],a[i]);	
		}
	}
	for(int i=0;i<m;i++){
		scanf("%d%d",&l,&r);
		printf("%d\n",ans[l-1][r-1]);
	}
	return 0;
}
