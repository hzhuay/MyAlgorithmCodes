#include<iostream>
#include<cstdio>
#define MAX 100005
using namespace std;
bool mark[MAX];
int main(){
	int X,Y,l,r,j=2,i,sum=0;
	cin>>X>>Y;
	mark[1]=true;
	l=min(X,Y);
	r=max(X,Y);
	for(i=2;i<=r&&i*j<=r;i++){
		for(;i*j<=r;j++)
			if(!mark[j])mark[i*j]=true;	
		j=2;
	}
	for(i=l;i<=r;i++)if(!mark[i])sum++;
	printf("%d",sum);
	return 0;
}
