#include<cstdio>
#include<algorithm>
using namespace std;
struct P{
	int a,b;
	bool operator < (const &P y)const{
		return b>y,b;
	}
}p[205];
int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d%d",&p[i].a,&p[i].b);
	sort(p,p+N);
	while(N--){
		
	}
	return 0;
}
