#include<cstdio> 
const int maxn=100000+5;
char s[maxn];
int p[maxn],sum[maxn];
int compare_average(int x1,int x2,int x3,int x4){
	return (sum[x2]-sum[x1-1])*(x4-x3+1)-(sum[x4]-sum[x3-1])*(x2-x1+1);//比较p1p2的斜率和p3p4的斜率 
}
int main(){
	int kase;
	scanf("%d",&kase);
	while(kase--){
		int n,L;
		scanf("%d%d%s",&n,&L,s+1);
		sum[0]=0;
		for(int i=1;i<=n;i++)
			sum[i]=sum[i-1]+s[i]-'0';
		int ansL=1,ansR=L;
		
		int i=0,j=0;
		for(int t=L;t<=n;t++){
			while(j-i>1&&compare_average(p[j-2],t-L,p[j-1],t-L)>=0)j--;// remove concave points
			p[j++]=t-L+1;// new candidate
			while(j-i>1&&compare_average(p[i],t,p[i+1],t)<=0)i++;// update tangent point	
			//比较和更新答案 
			int c=compare_average(p[i],t,ansL,ansR);
			if(c>0||c==0&&t-p[i]<ansR-ansL){
				ansL=p[i];ansR=t;
			}
		}
		printf("%d %d\n",ansL,ansR);
	}
	return 0;
}
