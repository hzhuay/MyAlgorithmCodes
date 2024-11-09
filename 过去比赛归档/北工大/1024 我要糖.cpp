#include<cstdio>
int main(){
	int T,a,b;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&a,&b);
		if(a==b)puts("Nooooo!!");
		else printf("%c %d\n","21"[a>b],a>b?a-b:b-a);
	}
}
