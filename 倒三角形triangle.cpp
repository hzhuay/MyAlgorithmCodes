#include<iostream>
using namespace std;
int main(){
	int n,i,j,row;
	scanf("%d",&n);
	row=n;
	while(row){
		for(i=1;i<=n-row;i++){
			printf(" ");
		}
		for(j=1;j<=2*n+1-2*i;j++){
			printf("*");
		}
		for(j=1;j<=i;j++){
			printf(" ");
		}
		puts("");
		row--;
	}
	return 0;
}
