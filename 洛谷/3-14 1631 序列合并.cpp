#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+5;
int a[maxn],b[maxn],ans[maxn];
struct Pair{
	int i,j,a,b,s;
	bool operator > (const Pair& x)const{return s>x.s;}
	Pair(int _i,int _j,int _a,int _b):i(_i),j(_j),a(_a),b(_b){
		s=a+b;	
	}
};
priority_queue<Pair,vector<Pair>,greater<Pair> >q;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<n;i++)scanf("%d",&b[i]);
	for(int i=0;i<n;i++)q.push(Pair(i,0,a[i],b[0]));
	for(int i=0;i<n;i++){
		Pair tmp=q.top();
		q.pop();
		printf("%d ",tmp.a+tmp.b);
		q.push(Pair(tmp.i,tmp.j+1,a[tmp.i],b[tmp.j+1]));
		
	}
	return 0;
}
