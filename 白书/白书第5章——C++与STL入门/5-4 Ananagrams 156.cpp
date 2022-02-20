#include<iostream>
#include<string>
#include<cctype>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
map<string,int>cnt;
vector<string>words;
string repr(const string& s){
	string ans=s;
	for(int i=0;i<ans.length();i++)
		ans[i]=tolower(ans[i]);
	sort(ans.begin(),ans.end());
	return ans;
}
int main(){
	int n=0;
	string s;
	//cnt.clear();//这句话加了也能ac 
	while(cin>>s){
		if(s[0]=='#')break;
		words.push_back(s);
		string r=repr(s);//得到标准化的单词 
		//if(!cnt.count(r))cnt[r]=0;//这句话我注释掉后也ac 
		cnt[r]++;
	}
	vector<string>ans;
	for(int i=0;i<words.size();i++)
		if(cnt[repr(words[i])]==1)ans.push_back(words[i]);
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<endl;
	return 0;
}
