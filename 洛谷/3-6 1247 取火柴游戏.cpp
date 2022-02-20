//Nim模型：求出每个石堆数的异或值,a1^a2^a3^......^an 
//若为0，先手必输；若不为零，先手要让该值为0，让后手输 
#include<cstdio>
int a[500005];
int main(){
	int n,nim=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		nim^=a[i];
	}
	if(nim==0)puts("lose");
	else{
		for(int i=0;i<n;i++){
//nim=a1^a2^a3^......^an，所以a1^(a2^nim)^...^an=0 
			if((a[i]^nim)<a[i]){//a[i]^nim是剩下的石头数，应小于a[i]才是合法操作 
				printf("%d %d\n",a[i]-(a[i]^nim),i+1);
				a[i]^=nim;
				break; 
			}
		}
		for(int i=0;i<n;i++)printf("%d ",a[i]);
	}
	return 0;
}
