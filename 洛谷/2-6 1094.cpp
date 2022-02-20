#include<cstdio>
#include<algorithm>
using namespace std;
int p[30005],vis[30005];
int main(){
	int n,w,cnt=0;
	scanf("%d%d",&w,&n);
	for(int i=0;i<n;i++)scanf("%d",&p[i]);
	sort(p,p+n);
	int i=0,j=n-1;
	while(i<j){
		while(p[i]+p[j]>w){
			cnt++;
			j--;			
		}
		cnt++;
		i++;j--;
	}
	if(i==j)cnt++;
	printf("%d",cnt);
	return 0;
} 
