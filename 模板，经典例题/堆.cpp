#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
priority_queue<int,vector<int>,greater<int> >q;
int main(){
	int n,a;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a);
		if(a==1){
			scanf("%d",&a);
			q.push(a);
		}else if(a==2)printf("%d\n",q.top());
		else q.pop();
	}
	return 0;
}
