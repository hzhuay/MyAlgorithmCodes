#include<cstdio>
#include<cstring>
#include<algorithm>
#define M 1005
using namespace std;
char str[M];
int A[M],B[M],C[M*M];
int main(){
	int i,j,len,alen,n,x,k=1;
	while(scanf("%s %d",str,&n)!=EOF){
		len=strlen(str);
		for(i=0;i<len;i++)
			if(str[i]=='.')
				break;
		if(i==len-1)x=0;
		else {
			for(j=i;j<len;j++)str[j]=str[j+1];
			len--;
			x=len-i;
		}
		for(i=len-1;i>=0;i--){
			A[i]=str[len-i-1]-'0';
			B[i]=A[i];
		}
		
		while(k<n){
			for(i=0;i<len*k;i++)
				for(j=0;j<len;j++){
					C[j+i]+=A[j]*B[i];
					C[i+j+1]+=C[i+j]/10;
					C[i+j]%=10;
				}
			for(i=1;i<=M;i++)B[i]=C[i];
			for(i=1;i<=M;i++)printf("%d",A[i]);puts("");
			memset(C,0,sizeof(C));
			k++;
		}
		for(i=alen*alen;i>=0;i--)
			if(C[i])break;
		if(i==-1)printf("0");
		else for(j=i;j>=0;j--)printf("%d",C[j]);
		memset(str,0,sizeof(str));
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		memset(C,0,sizeof(C));
	}
	return 0;
}
