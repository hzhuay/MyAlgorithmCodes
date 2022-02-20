#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=50000;
int list[maxn+5],per[maxn+5];
int main(){
	for(int i=1;i<maxn;i++)list[i+1]=list[i]+i;
	int n,m,l;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)per[i]=i+1;	
	while(list[l]<m)l++;l=n-l;
	do{
		int ans=0;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if(per[i]>per[j])ans++;
		
		if(ans==m)break;
	}while(next_permutation(per+l,per+n));
	for(int i=0;i<n;i++)printf("%d ",per[i]);
	for(int i=0;i<n;i++)printf("%d ",per[i]);
	puts("");
	return 0;
}
