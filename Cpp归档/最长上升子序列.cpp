#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100005;
int a[maxn],maxlen[maxn];
int main(){
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxlen[i]=1;
	}
	for(int i=2;i<=n;i++)
		for(int j=1;j<i;j++)
			if(a[i]>a[j])maxlen[i]=max(maxlen[i],maxlen[j]+1);
	for(int i=1;i<=n;i++)if(ans<maxlen[i])ans=maxlen[i];
	printf("%d",ans);
	return 0;
}
