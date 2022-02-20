#include<cstdio>
#include<cstring>
#include<algorithm>
#define M 1005
using namespace std;
char str[M],str2[M];
int A[M],B[M],C[M+100],k=0;
bool compare(int A[],int B[],int i,int alen){
	for(int j=i;j<=i+alen;j++){
		if(C[i]<B[i])return false;
	}
	return true;
}
void pushback(int B[],int len2,int k){
	for(int i=len2-1+k;i>=0;i--){
			B[i+1]=B[i];
		}
	k++;
	return;
}
int main(){
	int i,len,len2,alen;
	scanf("%s %s",str,str2);
	len=strlen(str);
	len2=strlen(str2);
	for(i=0;i<=len-1;i++)
		A[i]=str[i]-'0';
	for(i=0;i<=len2-1;i++)
		B[i]=str2[i]-'0';//准备处理工作，不需要改动	
	alen=min(len,len2);
	if(A[0]>B[0]){
		while(k<100){
			while(compare(A,B,i,alen)){
				for(i=k-1;i<alen-1+k;i++){
					A[i]-=B[i];
					if(A[i]<0){
						A[i-1]--;
						A[i]+=10;
					}
				}
			}
			pushback(B,len2,k);
		}
	}else{
		pushback(B,len2,k);
		while(k<=100){
			while(compare(A,B,i,alen)){
				for(i=k-1;i<alen-1+k;i++){
					A[i]+=B[i];
					if(A[i]<0){
						A[i-1]--;
						A[i]+=10;
					}
				}
			}
			pushback(B,len2,k);
		}
	}		
	if(C[alen]>0)alen++;
	if(len>=len2){
		for(i=alen-1;i>=0;i--)
		printf("%d",C[i]);
	}else{
		printf("%s","-");
		for(i=alen-1;i>=0;i--)
		printf("%d",C[i]);
	}
	puts("");
	return 0;
}
