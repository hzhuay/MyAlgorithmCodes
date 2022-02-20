#include<cstdio>
#include<cmath>
int count_divisors(int x){
	int cnt=0,R=sqrt(x+0.5);
	for(int i=1;i<=R;i++)
		if(x%i==0)cnt++;
	return R*R==x?cnt*2-1:cnt*2;
}
int main(){
//	freopen("in.txt","r",stdin);
	int kase,L,U;
	scanf("%d",&kase);
	while(kase--){
		scanf("%d%d",&L,&U);
		int num,ans=0,tmp;
		for(int i=L;i<=U;i++){
			tmp=count_divisors(i);
			if(ans<tmp){
				ans=tmp;
				num=i;
			}
		}
		printf("Between %d and %d, %d has a maximum of %d divisors.\n",L,U,num,ans);
	}
	return 0;
}
