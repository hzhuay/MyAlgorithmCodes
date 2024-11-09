#include<cstdio>
#include<algorithm>
#define M 100005
using namespace std;
pair<int,int>p[M];
int main(){
	int n,i,t=0,ans=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d %d",&p[i].second,&p[i].first);
	sort(p,p+n);
	for(i=0;i<n;i++)
		if(t<p[i].second){
			ans++;
			t=p[i].first;
		}
	printf("%d",ans);
	return 0;
}
