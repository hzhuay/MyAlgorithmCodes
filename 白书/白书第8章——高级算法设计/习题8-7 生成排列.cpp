#include<cstdio>
#include<vector>
using namespace std;
int n,p[305];
vector<int>ans;
bool judge(){
	for(int i=1;i<n;i++)
		if(p[i]<p[i-1])return false;
	return true;
}
int main(){
	while(scanf("%d",&n)&&n){
		ans.clear();
		for(int i=0;i<n;i++)
			scanf("%d",&p[i]);
		while(1){
			if(judge())break;
			if(p[0]!=n&&p[0]>p[1]){
				swap(p[0],p[1]);
				ans.push_back(1);
			}
		
			if(judge())break;
			ans.push_back(2);
			int tmp=p[n-1];
			for(int i=n-2;i>=0;i--)
				p[i+1]=p[i];
			p[0]=tmp;
		}
		/*
		for(int i=ans.size()-1;i>=0;i--)
			printf("%d",ans[i]);
		*/
		for(int i=0;i<ans.size();i++)
			printf("%d",ans[i]);
		puts("");
		
	}
	return 0;
}
