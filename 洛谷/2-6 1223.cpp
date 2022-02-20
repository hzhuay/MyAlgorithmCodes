#include<cstdio>
#include<algorithm>
using namespace std;
struct T{
    int n,t;
}p[1005];
bool cmp(T a,T b) {
    if(a.t!=b.t)
        return a.t<b.t;
    return a.n<b.n;
}
int main(){
	int n;
	double ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
        scanf("%d",&p[i].t);
        p[i].n=i;
    }
    sort(p+1,p+n+1,cmp);
    for(int i=1;i<=n;i++)printf("%d ",p[i].n);
    for(int i=1;i<=n;i++)ans+=i*p[n-i].t;
    ans/=n;
	printf("\n%.2f",ans);
	return 0;
}
