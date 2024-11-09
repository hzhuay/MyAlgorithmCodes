#include<iostream>
using namespace std;
int a[105],b[55];
int f(int n,int m){
	if(n<1||m<1) return 0;
	if(n==1||m==1)return 1;
	if(n<m)return f(n,n);
	if(n==m)return f(n,m-1)+1;
	if(n>m)return f(n,m-1)+f(n-m,m);
}
int main(){
	for(int i=1;i<=100;i++){
		cin>>a[i];
	}
	for(int i=1;i<=50;i++){		
		b[i]=f(i,i);
	}
	for(int i=1;i<=100;i++){
		if(a[i])cout<<b[a[i]];
	}
	return 0;
}

