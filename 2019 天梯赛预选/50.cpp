#include<cstdio>
int pow[10]={1};
int a[10];
int main(){
	int L,cnt=0,tar;
	scanf("%d%d",&L,&tar);
	for(int i=1;i<=6;i++){
		pow[i]=pow[i-1]*26;
	}
	tar--;
	for(int i=6;i>=0;i--){
		while(tar>=pow[i]){
			tar-=pow[i];
			a[i]++;
		}
	}
	for(int i=L-1;i>=0;i--)
		printf("%c",'a'+25-a[i]);
	return 0;
}
