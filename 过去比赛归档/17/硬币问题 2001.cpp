#include<cstdio>
int c[6],p[6]={1,5,10,50,100,500};
int main(){
	int A,i,ans=0;
	scanf("%d",&A);
	for(i=0;i<6;i++)scanf("%d",&c[i]);
	for(i=5;i>=0;i--){
		while(A-p[i]>=0&&c[i]){
			A-=p[i];
			c[i]--;
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
