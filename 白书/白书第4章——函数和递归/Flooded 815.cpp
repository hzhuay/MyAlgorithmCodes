#include<cstdio>
#include<cstring>
#define EPS 0.000001
int alt[35][35],alti[2500];
int min(int n,int m){
	int mini=alt[0][0];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(mini>alt[i][j])mini=alt[i][j];
	return mini;
}
int main(){
	//freopen("in.txt","r",stdin);
	int n,m,kase=1;
	while(scanf("%d%d",&n,&m),n!=0){
		int low,V,S=n*m,tmp=0,count=0,i;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				scanf("%d",&alt[i][j]);
				alti[alt[i][j]+100]++;
			}
		scanf("%d",&V);
		low=min(n,m)+100;
		for(i=low;;i++){
			if(alti[i]){
				tmp+=(alti[i]*100);
				count+=alti[i];
			}
			if(tmp<V)
				V-=tmp;
			else//tmp>=V
				break;
		}
		printf("Region %d\n",kase++);
		printf("Water level is %.2f meters.\n",i+V*1.0/tmp-100+EPS);
		printf("%.2f percent of the region is under water.\n\n",100.0*count/S+EPS);
		memset(alti,0,sizeof(alti));
		memset(alt,0,sizeof(alt));
	}
	return 0;
}
