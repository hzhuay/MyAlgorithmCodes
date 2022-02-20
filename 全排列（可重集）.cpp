#include<cstdio>
int P[10];
void print_permutation(int n,int* A,int cur){
	if(cur==n){
		for(int i=0;i<n;i++)
			printf("%d",A[i]);
			puts("");
	}
	else for(int i=0;i<n;i++){
		if(!i||P[i]!=P[i-1]){
			int c1=0,c2=0; 
			for(int j=0;j<cur;j++)
				if(A[j]==P[i])c1++;
			for(int j=0;j<n;j++)
				if(P[j]==P[i])c2++;
			if(c1<c2){
				A[cur]=P[i];
				print_permutation(n,A,cur+1);
			}
		}
	}
}
int main(){
	int A[10],n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&P[i]);
	print_permutation(n,A,0);
	return 0;
}
