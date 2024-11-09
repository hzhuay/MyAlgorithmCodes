#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+5;
string name,fresh[maxn];
int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
	int n,m;
	cin>>n>>m;
	getline(cin,name);
	for(int i=0;i<n;i++)getline(cin,fresh[i]);
	while(m--){
		getline(cin,name);
		if(*lower_bound(fresh,fresh+n,name)==name)cout<<"QAQ"<<'\n';
		else cout<<"TAT"<<'\n';
	}
	return 0;
}
