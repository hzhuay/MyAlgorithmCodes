#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[12],b[12];
int main(){
	int i=0,j=0;
	memset(a,1001,sizeof(a));
	memset(b,1001,sizeof(b));
	cin>>a[i]>>b[j];
	while(a[i++])a[i]=a[i-1]/2;
	while(b[j++])b[j]=b[j-1]/2;
	for(i=0;i<10&&a[i]!=1001;i++)
		for(j=0;j<10&&b[j]!=1001;j++)
			if(a[i]==b[j]){
				printf("%d",a[i]);
				return 0;
			}
	return 0; 
}
