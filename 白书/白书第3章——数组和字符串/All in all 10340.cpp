#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[100005],t[100005];
int main(){
	int mark,p=0,lens,lent;
	while(scanf("%s %s",s,t)!=EOF){
		mark=0;
		p=0;
		lens=strlen(s);
		lent=strlen(t);
		for(int i=0;i<lens;i++){
			for(int j=p;j<lent;j++){
				if(s[i]==t[j]){
					mark++;
					p=j+1;
					break;
				}
			}
		}
		if(mark==lens)puts("Yes");
		else puts("No");
		memset(s,0,sizeof(s));
		memset(t,0,sizeof(t));
	}
	return 0;
}
