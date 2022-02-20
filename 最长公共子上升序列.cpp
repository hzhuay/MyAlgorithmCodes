#include<iostream>
#include<cstdio>
#include<algorithm>
#define len 505
using namespace std;
int A[len],B[len],tmp1[len],tmp2[len],lena=0,lenb=0;
bool mark1[len],mark2[len]; 
int main(){
	int i,M1,M2,L,l1[len],l2[len],alen,j=1;
	scanf("%d",&M1);
	for(i=1;i<=M1;i++){
		scanf("%d",&tmp1[i]);
		mark1[tmp1[i]]=true;
	}
	scanf("%d",&M2);
	for(i=1;i<=M2;i++){
		scanf("%d",&tmp2[i]);
		mark2[tmp2[i]]=true;
	}
	for(i=1;i<=M1;i++)
		if(mark1[tmp1[i]]&&mark2[tmp1[i]])
			A[++lena]=tmp1[i];
	for(i=1;i<=M2;i++)
		if(mark1[tmp2[i]]&&mark2[tmp2[i]])
			B[++lenb]=tmp2[i];	
	
	return 0;
}
