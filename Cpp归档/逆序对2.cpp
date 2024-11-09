#include<bits/stdc++.h>
#define lowbit(x) (-x)&(x)
using namespace std;
const int maxn=1e6+10;
int t[maxn],n,result;
int query(int x){
	int ans=0;
	for(;x;x-=lowbit(x))
		ans+=t[x];
	return ans;
}
void add(int x){
	while(x<=maxn){
		t[x]++;
		x+=lowbit(x);
	}
}
int main(){    
	int temp;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&temp);
		add(temp);
		result += i - query(temp);
	}
	printf("%d\n",result);
	return 0;
}
