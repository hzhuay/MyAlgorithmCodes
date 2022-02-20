#include<cstdio>
#include<vector>
using namespace std;
int n;
vector<int>ans,p;
bool judge(){
	for(int i=1;i<n;i++)
		if(p[i]<p[i-1])return false;
	return true;
}
int main(){
	while(scanf("%d",&n)&&n){
		ans.clear();p.clear();
		for(int i=0;i<n;i++){
			int tmp;
			scanf("%d",&tmp);
			p.push_back(tmp);
		}
		while(1){
			if(judge())break;
			if(p[0]==n||p[0]<p[1]){
				p.insert(p.begin(),p[n-1]);
				p.resize(n);
				ans.push_back(2);
			}else{
				swap(p[0],p[1]);
				ans.push_back(1);
			}
		}
		for(int i=ans.size()-1;i>=0;i--)
			printf("%d",ans[i]);
		puts("");
	}
	return 0;
}
