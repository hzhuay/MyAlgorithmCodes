#include<cstdio>
#include<stack>
#include<cstring>
#include<iostream>
#define M 130
using namespace std;
char str[M];
stack<char>s;
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int kase;
	scanf("%d%*c",&kase);
	while(kase--){
		bool flag=true;
		fgets(str,M,stdin);
		int len=strlen(str)-1;
		for(int i=0;i<len;i++){
			if(str[i]==')'||str[i]==']'){
				if(s.empty()){flag=0;break;} 
				else{
					if((s.top()=='('&&str[i]==')')||(s.top()=='['&&str[i]==']'))s.pop();
					else{flag=0;break;}
				}
			}else s.push(str[i]);
		}
		if(flag&&s.empty())puts("Yes");
		else puts("No");
		while(!s.empty())s.pop();
	}
	return 0;
}
