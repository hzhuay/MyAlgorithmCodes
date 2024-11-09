#include<cstdio>
#include<cstring>
#include<algorithm>
#define M 1005
using namespace std;
char str[M],str2[M];
int A[M],B[M],C[M];
int main(){
	int i,len,len2,alen;
	scanf("%s %s",str,str2);
	len=strlen(str);
	len2=strlen(str2);
	for(i=0;i<len;i++)
		A[i]=str[len-i-1]-'0';
	for(i=len2-1;i>=0;i--)
		B[i]=str2[len2-i-1]-'0';	
	alen=max(len,len2);
	for(i=0;i<alen;i++){
		C[i]+=A[i]+B[i];
		if(C[i]>10){
			C[i+1]++;
			C[i]-=10;
		}
	}
	if(C[alen]>0)alen++;
	for(i=alen-1;i>=0;i--)
		printf("%d",C[i]);
	puts("");
	return 0;
}
