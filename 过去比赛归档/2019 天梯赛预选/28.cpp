#include<cstdio>
#include<cmath>
int p[1005][1005],k[1005];
double pa[1005],pb[1005];
int main(){
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d",&k[i]);
		for(int j=0;j<k[i];j++)scanf("%d",&p[i][j]);
	}
	scanf("%d%d",&a,&b);
	for(int i=0;i<m;i++){
		for(int x=0;x<k[i];x++){
			if(p[i][x]=a){
				for(int y=0;y<k[i];y++){
					if(p[i][y]*a<0){
						pa[abs(y)]+=1.0/k[i];
					}
				}
			}
			if(p[i][x]=b){
				for(int y=0;y<k[i];y++){
					if(p[i][y]*b<0){
						pb[abs(y)]+=1.0/k[i];
					}
				}
			}
		}
	}
	printf("%f %f\n",pa[abs(b)],pb[abs(a)]);
	for(int i=0;i<n;i++){
		
	}
	return 0;
}
