#include<cstdio>
const int maxn=100005;
int A[maxn],B[maxn];
int main(){
	int N,M,Q,ans=0;
	scanf("%d%d%d",&N,&M,&Q);
	for(int i=0;i<=N;i++)scanf("%d",A+i);
	for(int i=0;i<=M;i++)scanf("%d",B+i);
	for(int i=M;i>0;i--)B[i-1]+=B[i];
	for(int i=0;i<=N;i++)
		if(i+M>=Q)
			ans+=A[i]*B[Q-i];
	printf("%d",ans);
	return 0;
}
