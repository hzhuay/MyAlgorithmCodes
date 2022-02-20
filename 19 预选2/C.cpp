#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005];
int main(){
	int n,s=0,ans=0,last=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<n;i++){
		if(a[i+1]>a[i]||i==n-1){
			for(int j=s;j<=i;j++)b[j]=a[j];
			sort(b+s,b+i+1);
			last=max(b[(s+i)/2],last);
			for(int j=s;j<=i;j++){
				ans+=abs(a[j]-last);
				a[j]=last;		
			}
			s=i+1;
		}
	}
	printf("%d",ans);
	return 0;
}
