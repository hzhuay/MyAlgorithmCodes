#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char score[85];
int main(){
	int t,n=0,grade=0,i,len;
	cin>>t;
	for(i=1;i<=t;i++){
		scanf("%s",score);
		len=strlen(score);
		grade=0;
		n=0;
		for(int j=0;j<len;j++){
			if(score[j]=='O')grade+=++n;
			else n=0;
		}
		printf("%d\n",grade);
	}
	return 0;
}
