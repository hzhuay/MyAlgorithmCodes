#include<cstdio>
#include<cstring>
#include<algorithm>
#define M 1005
using namespace std;
char str[M],str2[M];
int A[M],B[M],C[M*M];
int main(){
	int i,len,len2,alen;
	scanf("%s %s",str,str2);
	len=strlen(str);
	len2=strlen(str2);
	for(i=len-1;i>=0;i--)
		A[i]=str[len-i-1]-'0';
	for(i=len2-1;i>=0;i--)
		B[i]=str2[len2-i-1]-'0';	
	alen=max(len,len2);
	for(i=0;i<len+len2+1;i++)
		for(int j=0;j<len;j++){
			C[j+i]+=A[j]*B[i];
			C[i+j+1]+=C[i+j]/10;
			C[i+j]%=10;
		}
	for(i=alen*alen;i>=0;i--)
		if(C[i])break;
	if(i==-1)printf("0");
	else for(int j=i;j>=0;j--)printf("%d",C[j]);
	return 0;
}
