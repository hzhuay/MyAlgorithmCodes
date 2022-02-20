#include<cstdio>
#include<map>
using namespace std;
const int maxn=1000000+5;
int A[maxn],last[maxn];
map<int,int>cur;
int main(){
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&A[i]);
			if(!cur.count(A[i]))last[i]=-1;
			else last[i]=cur[A[i]];
			cur[A[i]]=i;
		}
		int L=0,R=0,ans=0;
		while(R<n){
			while(R<n&&last[R]<L)R++;
			ans=max(ans,R-L);
			L++;
		}
		printf("%d\n",ans);
		/*
		for(int i=0;i<7;i++)printf("%d ",last[i]);
		puts("");
		for(int i=0;i<7;i++)printf("%d ",cur[A[i]]); 
		*/
	}
	return 0;
}
