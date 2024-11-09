#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int n;
	char *p;
	char A[]={"4567"},B[]={"123"},C[]={0};
	scanf("%d",&n);
	while(strlen(C)<n){
		p=strcat(B,A);
		char C[strlen(p)];
		strcpy(C,p);
	}
	return 0;
}

