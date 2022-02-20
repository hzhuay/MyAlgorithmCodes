#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
long long n,N[20];
bool is0(){//如果全是0的话返回false 
	for(int i=0;i<n;i++)
		if(N[i]!=0)return 1;
	return 0;
}
int main(){
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		memset(N,0,sizeof(N));
		cin>>n;
		for(int j=0;j<n;j++)cin>>N[j];
		int k1=0;
		while(is0()){
			if(k1++>1000)break;
			int x=N[0];
			for(int j=0;j<n-1;j++)
				N[j]=abs(N[j]-N[j+1]);
			N[n-1]=abs(N[n-1]-x);
		}
		if(!is0())puts("ZERO");
		else puts("LOOP");
	}
	return 0;
}
