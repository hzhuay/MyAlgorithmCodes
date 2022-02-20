#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 170 
using namespace std;
int sum[maxn];
void build(int p){
	int v;cin>>v;
	if(v==-1)return;
	sum[p]+=v;
	build(p-1);build(p+1);
}
bool init(){
	int v;cin>>v;
	if(v==-1)return false;
	memset(sum,0,sizeof(sum));
	int pos=maxn/2;
	sum[pos]=v;
	build(pos-1);build(pos+1);
}
int main(){
	//freopen("in.txt","r",stdin);
	int kase=0;
	while(init()){
		int p=0;
		while(sum[p]==0)p++;
		printf("Case %d:\n%d",++kase,sum[p++]);
		while(sum[p]!=0)printf(" %d",sum[p++]);
		printf("\n\n");
	}
	return 0;
}
