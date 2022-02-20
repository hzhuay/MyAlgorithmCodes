#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100005;
struct TYPE{
	int num,p;
	int ans=0;
}a[maxn];
bool cmpx(TYPE x,TYPE y){return x.num>y.num;}
bool cmpp(TYPE x,TYPE y){return x.p<y.p;}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int sum=0; 
		for(int i=0;i<n;i++){
			scanf("%d",&a[i].num);
			a[i].p=i;
			sum+=a[i].num;
		}
		if(sum%2==1){puts("No");continue;}
		sort(a,a+n,cmpx);
		int tmp=0;
		for(int i=0;i<n;i++){
			if(tmp<0){
				tmp+=a[i].num;
				a[i].ans=1;
			}else{
				tmp-=a[i].num;
				a[i].ans=-1;
			}
		}
		if(tmp!=0){puts("No");continue;}
		else{
			sort(a,a+n,cmpp);
			puts("Yes");
			for(int i=0;i<n;i++)
				printf("%d%c",a[i].ans," \n"[i==n-1]);
		}
		memset(a,0,sizeof(a));
	}
	return 0;
}
