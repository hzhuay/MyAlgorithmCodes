#include<set>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cctype>
#include<map>
#include<stack>
#include<algorithm>
#define All(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
using namespace std;
typedef set<int>Set;
map<Set,int>IDcache;
vector<Set>Setcache;
int ID(Set x){
	if(IDcache.count(x))return IDcache[x];
	Setcache.push_back(x);
	return IDcache[x]=Setcache.size()-1;
}
int main(){
	stack<int>s;
	int n,kase;
	scanf("%d",&kase);
	while(kase--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			string op;
			cin>>op;
			if(op[0]=='P')s.push(ID(Set()));
			else if(op[0]=='D')s.push(s.top());
			else{
				Set x1=Setcache[s.top()];s.pop();
				Set x2=Setcache[s.top()];s.pop();
				Set x;
				if(op[0]=='U')set_union(All(x1),All(x2),INS(x));
				if(op[0]=='I')set_intersection(All(x1),All(x2),INS(x));
				if(op[0]=='A'){x=x2;x.insert(ID(x1));}
				s.push(ID(x));
			}
			cout<<Setcache[s.top()].size()<<endl;
		}
		puts("***");
	}
	return 0;
}
