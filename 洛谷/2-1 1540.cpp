#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>mem;
int main(){
	int n,m,a,ans=0;
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		if(find(mem.begin(),mem.end(),a)==mem.end()){
			mem.push_back(a);
			ans++;
		}
		if(mem.size()>m){
			mem.erase(mem.begin());
		}
	}
	printf("%d",ans);
	return 0;
} 
