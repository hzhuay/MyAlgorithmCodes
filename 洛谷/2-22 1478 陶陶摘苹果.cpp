#include<cstdio>
#include<algorithm>
using namespace std;
struct apple{
	int h,v;
    bool operator < (const apple& x)const{return v<x.v;}
}ap[5005];
int main(){
	int n,s,a,b,h,ans=0;
	scanf("%d%d%d%d",&n,&s,&a,&b);
	h=a+b;
	for(int i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		ap[i].h=a;
		ap[i].v=b;
	}
	sort(ap,ap+n);
	for(int i=0;i<n;i++){
		if(h<ap[i].h)continue;
		else if(s<ap[i].v)break;
		else{
			s-=ap[i].v;
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
