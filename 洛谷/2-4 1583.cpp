#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct People{
    int W,D,C,num;
    bool operator < (const People& x)const{
		if(W!=x.W)return W>x.W;
		else return num<x.num;
	}
}p[20005];
int E[15];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=10;i++)scanf("%d",&E[i]);
    for(int i=1;i<=n;i++){
    	scanf("%d",&p[i].W);
    	p[i].num=i;
	}
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++){
		p[i].D=i;
		p[i].C=(p[i].D-1)%10+1;
		p[i].W+=E[p[i].C];
	}
	sort(p+1,p+n+1);
	for(int i=1;i<=k;i++)printf("%d ",p[i].num);
    return 0;
}
