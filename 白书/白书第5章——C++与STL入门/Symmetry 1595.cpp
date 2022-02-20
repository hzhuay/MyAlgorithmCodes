#include<cstdio>
#include<set>
#define M 20005
using namespace std;
set<int>p[M],r;
int main(){
	//freopen("in.txt","r",stdin);
	int T,N,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		int max=-10000,min=10000;
		for(int i=0;i<N;i++){
			scanf("%d %d",&x,&y);
			y+=10000;
			r.insert(y);
			p[y].insert(x);
			if(max<x)max=x;
			if(min>x)min=x;
		}
		set<int>::iterator c=r.begin();
		set<int>::iterator a=p[*c].begin();
		set<int>::iterator b=p[*c].end();b--;
		int mid=*a+*b;
		bool mark=true;
		for(set<int>::iterator H=r.begin();H!=r.end();H++){
			int lim=(p[*H].size()+1)/2;
			bool flag=true;
			set<int>::iterator L=p[*H].begin();
			set<int>::iterator R=p[*H].end();R--;
			while(lim--){
				//printf("%d %d %d %d",*L,*R,k,*H);
				if(*L+*R!=mid){flag=0;break;}
				L++;R--;
			}
			if(!flag)mark=0;
		}
		if(mark)puts("YES");
		else puts("NO");
		for(set<int>::iterator H=r.begin();H!=r.end();H++)
			p[*H].clear();
		r.clear();
	}
	return 0;
}
