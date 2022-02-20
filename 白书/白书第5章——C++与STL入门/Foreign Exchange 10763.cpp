#include<cstdio>
#include<algorithm>
#include<cstring>
#define M 500005
using namespace std;
int a[M],b[M];
int main(){
	int n;
	while(scanf("%d",&n),n){
		for(int i=0;i<n;i++)scanf("%d %d",&a[i],&b[i]);
		sort(a,a+n);
		sort(b,b+n);
		if(memcmp(a,b,4*n)==0)puts("YES");
		else puts("NO");
	}
	return 0;
}
