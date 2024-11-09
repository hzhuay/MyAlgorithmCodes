#include<iostream>
#include<cstdio>
#define MAX 100000
using namespace std;
bool mark[MAX+5],flag=false;
int inv(int x){
	int y=0;
	while(x){
		y=y*10+x%10;
		x/=10;
	}
	return y;
}
int main(){
	int M,N,j=2,i,prime[1000]={0};
	cin>>M>>N;
	for(i=2;i<=MAX&&i*j<=MAX;i++){
		for(;i*j<=MAX;j++)
			if(!mark[j])mark[i*j]=true;	
		j=2;
	}
	mark[1]=true;
	//for(i=M,j=0;i<=N;i++)if(!mark[i])prime[j++]=i;
	for(i=M;i<=N;i++){
		if(!mark[i]&&!mark[inv(i)]){
			if(flag)printf(","); 
			printf("%d",i);
			flag=true;
		}
	}
	if(!flag)puts("No");
	return 0;
}
