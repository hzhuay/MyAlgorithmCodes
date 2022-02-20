#include<cstdio>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int> >q;
int main(){
	int n,ans=0,tmp,a,b;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		q.push(tmp);
	}
	while(q.size()!=1){
		a=q.top();q.pop();
		b=q.top();q.pop();
		ans+=a+b;
		q.push(a+b);
	}
	printf("%d",ans);
	return 0;
}
