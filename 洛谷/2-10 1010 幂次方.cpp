#include<bits/stdc++.h>
using namespace std;
int p[20]={1},m=14;
int find(int n){
	for(int i=1;i<15;i++)if(p[i]>=n&&p[i+1]<n)return i;
}
void dfs(int cur){
	if(cur==0)return;
	for(int i=m;i>=0;i--){
		if(p[i+1]>cur&&cur>=p[i]){
			if(i==0)printf("2(0)");
			else if(i==1)printf("2");
			else if(i>1){
				printf("2(");
				dfs(i);
				printf(")");
			}
			if(cur!=p[i]){
				printf("+");
				dfs(cur-p[i]);
			}
		}
	}
}
int main(){
	int n; 
	scanf("%d",&n);
	for(int i=1;i<=15;i++)p[i]=p[i-1]*2;
	dfs(n);
	return 0;
}  
