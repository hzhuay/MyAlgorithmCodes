#include<stdio.h>
#include<algorithm>
using namespace std;
int main() {
    int n,m,ans=0,tmp,now=0;
    scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		if(now+tmp>m){
			ans++;
			now=0;
		}
		now+=tmp;
	}
	if(now!=0)ans++;
	printf("%d",ans);
    return 0;
}
