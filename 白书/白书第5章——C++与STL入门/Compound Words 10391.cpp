#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string,bool>mp;
string str[120005];
int main(){
	int n=0;
	while(cin>>str[n])
		mp[str[n++]]=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<str[i].size();j++){
			string s1=str[i].substr(0,j);
			string s2=str[i].substr(j);
			if(mp[s1]&&mp[s2]){
				cout<<str[i]<<endl;
				break;
			}
		}
	return 0;
}
