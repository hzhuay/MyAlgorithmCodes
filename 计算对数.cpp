#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define M 105
using namespace std;
char str[M],str2[M];
int A[M],B[M],C[2*M],D[2*M];
int compare(int l1,int l2){
	if(l1>l2)return 1;
	else if(l1<l2)return 3;
	else {
		for(int z=l1;z>=0;z--){
			if(C[z]>B[z])return 1;
			else if(C[z]<B[z])return 3;
		}
	}
	return 2;
}
int main(){
	int i,len,len2,ans=1;
	scanf("%s %s",str,str2);
	len=strlen(str);
	len2=strlen(str2);
	for(i=len-1;i>=0;i--)
		A[i]=str[len-i-1]-'0';
	for(i=len2-1;i>=0;i--)
		B[i]=str2[len2-i-1]-'0';	
	for(int j=0;j<=len;j++)D[j]=A[j];
	while(compare(len,len2)==3){
		ans++;
		for(int j=0;j<=len;j++)C[j]=0;	
		for(i=0;i<len+1;i++)
			for(int j=0;j<len;j++){
				C[j+i]+=A[j]*D[i];
				C[i+j+1]+=C[i+j]/10;
				C[i+j]%=10;
			}
		len<<=1;
		while(C[len]==0&&len>=0)len--;
		len++;
		for(int j=0;j<=len;j++)D[j]=C[j];
	}
	if(compare(len,len2)==2)printf("%d\n",ans);
	else printf("%d\n",ans-1);
	return 0;
}
