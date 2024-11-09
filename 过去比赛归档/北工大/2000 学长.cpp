#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+5;
char name[30],fresh[maxn][30];
int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)cin.getline(fresh[i],25);
	while(m--){
		cin.getline(name,25);
		int L=1,R=n,mid,res;
		while(L<=R){
			mid=(L+R)/2;
			res=strcmp(fresh[mid],name);
			if(res==0)break;
			if(res>0)R=mid-1;
			else L=mid+1;
		}
		if(res==0)cout<<"QAQ"<<'\n';
		else cout<<"TAT"<<'\n';
	}
	return 0;
}
