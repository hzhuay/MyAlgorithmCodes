#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=305;
bool mark[maxn];
struct Course{
	int a;
	int b;
	bool operator < (const Course& x)const{return b<x.b;}
}c[maxn];
int main(){
	int N;
	while(scanf("%d",&N),N!=0){
		for(int i=0;i<N;i++)
			scanf("%d%d",&c[i].a,&c[i].b);
		sort(c,c+N);
		int maxans=0; 
		for(int st=0;st<5;st++){
			int ans=0; 
			for(int i=st;i<=1000;i+=5){
				for(int j=0;j<N;j++){
					if(i>=c[j].a&&i<c[j].b&&!mark[j]){
						mark[j]=1;
						ans++;
						break;
					}
				}
			}
			memset(mark,0,sizeof(mark));
			maxans=max(ans,maxans);
		}
		printf("%d\n",maxans);
		memset(c,0,sizeof(c));
	}
	return 0;
}
