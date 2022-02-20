#include<bits/stdc++.h>
using namespace std;
const int maxn=10000;
int f[maxn+5],p[maxn+5];
bool prime[maxn+5];
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void build_prime(){
	for(int i=2;i<=maxn;i++)prime[i]=true;
	int m=sqrt(maxn+0.5);
	for(int i=2;i<=m;i++)
		if(prime[i])
			for(int j=i*i;j<=maxn;j+=i)
				prime[j]=false;
}
inline int change(int x){
	if(x<10000)return (x/1000)*(x/1000)+(x/100%10)*(x/100%10)+(x/10%10)*(x/10%10)+(x%10)*(x%10);
	else return 1;
}
void build_lucky(){
	for(int i=1;i<=maxn;i++){
		f[find(i)]=find(change(i));
	}
}
int main(){
	for(int i=1;i<=maxn;i++)f[i]=i;
	build_prime();
	//build_lucky();
	
	int l,r;
	scanf("%d%d",&l,&r);
	for(int i=1;i<=maxn;i++){
		f[find(change(i))]=find(i);
		printf("%d %d\n",i,change(i));
	}
	
	for(int i=l;i<=r;i++){
		if(f[i]==1){
			printf("%d\n",i);
		}
	}
	/*
	for(int i=l;i<=r;i++){
		printf("%d %d\n",i,f[i]);
	}
	*/
	return 0;
}
