#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#define M 10005
using namespace std;
int v[M],ans[M],a=1,b=1,m=1;
string str;
vector<int>A[M];
void DFS(int x){
	printf("%d ",v[x]);
	if(!A[x].empty())
		for(int i=0;i<(int)A[x].size();i++)
			DFS(A[x][i]);
	ans[b++]=v[x];
}
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int tmp,i=1;
	while(scanf("%d",&v[i])!=EOF){
		getline(cin,str);
		stringstream s(str);
		while(s>>tmp){	
			A[i].push_back(tmp);
			m++;
		}
		i++;
	}
	DFS(1);
	puts("");
	for(int i=1;i<b;i++){
		printf("%d",ans[i]);
		if(i!=m)printf(" ");
	}
	return 0;	
}
