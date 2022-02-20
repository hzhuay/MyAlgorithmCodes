#include<bits/stdc++.h>
using namespace std;
int a[100005],n,m;
bool check(int lim){
	int cnt=0,cur=0;
	for(int i=0;i<n;i++){
		if(cur+a[i]>lim){
			cur=a[i];
			cnt++;
		}else cur+=a[i]; 
	}
	return cnt>=m;
}
int main(){
	int L=0,R=0,mid;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		L=max(L,a[i]);
		R+=a[i];
	}
	while(L<=R){
		mid=(L+R)/2;
		if(check(mid))L=mid+1;
		else R=mid-1;
	}
	printf("%d",L);
	return 0;
} 
