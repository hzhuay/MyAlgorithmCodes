#include<bits/stdc++.h>
using namespace std;
int main(){
	char str[100];
	fgets(str,100,stdin);//会读入行末\n 
	printf("%s",str);
	cin.getline(str,100);//不会读入行末\n 
	printf("%s\n",str);
	string s;
	getline(cin,s);//不会读入行末\n 
	cout<<s<<'\n';
	printf("11"); 
	return 0;
}
