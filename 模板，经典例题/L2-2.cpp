#include<cstdio>
#include<algorithm>
using namespace std;
struct Item{
	double w,v;
	bool operator < (const Item& x)const{return v/w>x.v/x.w;}
}it[1005];
int main(){
	int n;
	double d,ans=0;
	scanf("%d%lf",&n,&d);
	for(int i=0;i<n;i++)scanf("%lf",&it[i].w);
	for(int i=0;i<n;i++)scanf("%lf",&it[i].v);
	sort(it,it+n);
	//for(int i=0;i<n;i++)printf("%f %f\n",it[i].w,it[i].v);
	for(int i=0;i<n;i++){
		if(d>=it[i].w){
			d-=it[i].w;
			ans+=it[i].v;
		}else{
			ans+=d/it[i].w*it[i].v;
			break;
		}
	}
	printf("%.2f",ans);
	return 0;
}
