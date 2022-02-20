#include<cstdio>
#include<cstring>
int H[10][15]; 
int main(){
	freopen("in.txt","r",stdin);
	int kase;
	scanf("%d",&kase);
	while(kase--){
		for(int i=1;i<=5;i++){
			for(int j=1;j<=i;j++){
				scanf("%d",&H[i*2-1][2*j-1]);
			}
		}
		for(int i=2;i<=5;i++){
			for(int j=1;j<i;j++){
				H[2*i-1][2*j]=(H[2*i-3][2*j-1]-H[2*i-1][2*j-1]-H[2*i-1][2*j+1])/2;
				H[2*i-2][2*j-1]=H[2*i-1][2*j-1]+H[2*i-1][2*j];
				H[2*i-2][2*j]=H[2*i-1][2*j+1]+H[2*i-1][2*j];
			}
		}
		for(int i=1;i<=9;i++)
			for(int j=1;j<=i;j++)
				printf("%d%c",H[i][j]," \n"[i==j]);
		memset(H,0,sizeof(H));
	}
	return 0;
}
 
