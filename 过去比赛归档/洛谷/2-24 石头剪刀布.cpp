#include<cstdio>
int mark[10][10]={{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};
int a[205],b[205];
int main(){
	int n,na,nb,A=0,B=0;
	scanf("%d%d%d",&n,&na,&nb);
	for(int i=0;i<na;i++)scanf("%d",&a[i]);
	for(int i=0;i<nb;i++)scanf("%d",&b[i]);
	for(int i=0;i<n;i++){
		A+=mark[a[i%na]][b[i%nb]];
		B+=mark[b[i%nb]][a[i%na]];
	}
	printf("%d %d",A,B);
	return 0;
}
