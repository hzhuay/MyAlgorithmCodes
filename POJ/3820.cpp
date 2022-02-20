#include<cstdio>
#include<cstring>
#include<sstream>
#include<string>
#include<iostream>
#include<stack>
using namespace std;
stack<string>tag;
const int size=100000;
char line[size];
bool isLegalHex(char c){return ('0'<=c&&c<='9')||('a'<=c&&c<='f')||('A'<=c&&c<='F');}
bool isLegalTag(char c){return ('0'<=c&&c<='9')||('a'<=c&&c<='z');}
bool judge(){
	int length=strlen(line);
	for(int i=0;i<length;){
		if(line[i]=='>')return false;
		if(line[i]=='<'){
			i++;
			if(line[i]=='/'){//</tag>,出栈 
				i++;
				if(line[i]=='>')i++;//跳过
				else{
					if(tag.empty())return false;
					string s=tag.top();
					int len=s.length();
					for(int j=0;j<len;j++){
						if(s[j]!=line[i++])return false;
					}
					tag.pop();
					if(line[i++]!='>')return false;
				}
			}else{//<tag>,<tag/>
				int now=i;
				while(true){
					if(line[i]=='/'){
						i++;
						if(line[i++]=='>')break;
						else return false;
					}
					else if(line[i]=='>'){
						tag.push(string(line+now,line+i));
						i++;
						break;
					}else if(isLegalTag(line[i]))i++;
					else return false;
				}
			}
		}else if(line[i]=='&'){
			i++; 
			if((line[i]=='g'&&line[i+1]=='t'&&line[i+2]==';')||(line[i]=='l'&&line[i+1]=='t'&&line[i+2]==';'))i+=3;//&gt;||&It;
			else if(line[i]=='a'&&line[i+1]=='m'&&line[i+2]=='p'&&line[i+3]==';')i+=4;//&amp;
			else if(line[i]=='x'){// 16进制数 
				i++;					
				if(!(isLegalHex(line[i])&&isLegalHex(line[i+1])))return false;					
				i+=2;					
				while(true){
					if(line[i]==';')break;		
					else if(isLegalHex(line[i])&&isLegalHex(line[i+1]))i+=2;				
					else return false;
				}
			}else return false;
		}else if(line[i]>=32&&line[i]<=127)i++;
		else return false;
	}
	if(!tag.empty())return false;
	return true;	
}
int main(){
	//freopen("in2.txt","r",stdin);
	while(cin.getline(line,size)){
		if(judge())puts("valid");
		else puts("invalid");
		while(!tag.empty())tag.pop();
		memset(line,0,sizeof(line));
	}
	return 0;
}
