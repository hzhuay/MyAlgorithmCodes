#include<cstdio>
#include<stack>
using namespace std;
const int MAXN=1010;
int n,target[MAXN];
int main(){
	//freopen("in.txt","r",stdin);
	while(scanf("%d",&n),n!=0){
		stack<int>s;
		int tmp;
		while(scanf("%d",&tmp),tmp!=0){
			target[1]=tmp;
			for(int i=2;i<=n;i++)scanf("%d",&target[i]);
			int A=1,B=1;
			bool ok=1;
			while(B<=n){
				if(A==target[B]){A++;B++;}
				else if(!s.empty()&&s.top()==target[B]){s.pop();B++;}
				else if(A<=n)s.push(A++);
				else {ok=0;break;}
			}
			printf("%s\n",ok?"Yes":"No");
		}
		puts("");	
	}
	return 0;
}
