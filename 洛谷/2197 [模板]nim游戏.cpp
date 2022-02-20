#include<cstdio>
#include<cstring>
int main(){
	int n,T;
	scanf("%d",&T);
	while(T--){
		int nim=0,tmp;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&tmp);
			nim^=tmp;
		}
		if(nim==0)puts("No");
		else puts("Yes");
	}
	return 0;
} 
