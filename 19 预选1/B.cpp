#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+5;
char str[maxn];
int main(){
	cin.getline(str,maxn);
	int len=strlen(str);
	for(int i=0;i<len;i++){
		if(str[i]=='p'&&str[i+1]=='c'){
			printf("mac");
			i++;
		}else putchar(str[i]);
	}
	return 0;
}
