#include<cstdio>
#include<algorithm>
using namespace std;
struct Farmer{
	int p,a;
	bool operator < (const Farmer& x)const{return p<x.p;}
}f[5005];
int main(){
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)scanf("%d%d",&f[i].p,&f[i].a);
	sort(f,f+m);
	for(int i=0;i<n;i++){
		if(n<f[i].a){
			ans+=n*f[i].p;
			break;
		}else{
			n-=f[i].a;
			ans+=f[i].p*f[i].a;
		}
	}
	printf("%d",ans);
	return 0;
}
