#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
using namespace std; 
char ans[8]={"http://"};
char ans1[5]={".../"};
char str[55];
bool check(){
	int len=strlen(str);
	if(len>50)return false;
	for(int i=0;i<7;i++){
		if(str[i]!=ans[i])return false;
	}
	int l=7,r=7;
	for(int i=0;i<4;i++){
		while(str[r]!=ans1[i]){
			if(!(str[r]>='0'&&str[r]<='9'))return false;
			else r++;
		}
		if(r-l==0||r-l>5)return false;
		r++;
		l=r;
	}
	return true;
}
int main(){
	scanf("%s",str);
	if(check())puts("Yes");
	else puts("No");
}
