#include<bits/stdc++.h>
using namespace std;
string s,m[10]={"-|| ||-","  |  | ","- |-| -","- |- |-"," ||- | ",    "-| - |-","-| -||-","- |  | ","-||-||-","-||- |-"};
int main(){
	int k;
	cin>>k>>s;
	for(int p=0;p<7;p++){
		if(p==2||p==5)continue;
		if(p%3==0){
			for(int i=0;i<s.length();i++){
				printf(" ");
				for(int j=0;j<k;j++)printf("%c",m[s[i]-48][p]);
				printf("  ");
			}
			puts("");
		}else{
			for(int t=0;t<k;t++){
				for(int i=0;i<s.length();i++){
					printf("%c",m[s[i]-48][p]);
					for(int j=0;j<k;j++)printf(" ");	
					printf("%c ",m[s[i]-48][p+1]);
				}
				puts("");
			}			
		}
	}
	return 0;
}
