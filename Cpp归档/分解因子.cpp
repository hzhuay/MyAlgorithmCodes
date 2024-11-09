#include<iostream>
#include<cstdio>
using namespace std;
int a[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
struct node{
	int d,c;
};
node divisors(int N,int i){
	node ans;
	ans.c=0;
	ans.d=N;
	if(a[i]>N)return ans;
	while(N%a[i]==0){
		N/=a[i];
		ans.c++;
	}
	ans.d=N;
	return ans;
}
int main(){
	int i,n;
	bool flag=false;
	scanf("%d",&n);
	for(i=0;i<25;i++){
		node tmp=divisors(n,i);
		if(flag&&tmp.d<n)printf("*");
		n=tmp.d;
		if(tmp.c)flag=1;
		if(tmp.c>1)printf("%d^%d",a[i],tmp.c);
		else if(tmp.c)printf("%d",a[i]);
	}
	return 0;
}
