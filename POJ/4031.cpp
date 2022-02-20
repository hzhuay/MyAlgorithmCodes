#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=105;
bool mark[maxn];
struct Function{
	int m;
	char c[maxn][5]; 
}f[maxn];
int ans[30],dir,flag,first;
long long x,y,tmpx,tmpy,
inline void plus(int[] billion){
	billion[0]++;
	for(int i=0;i<25;i++){
		if(billion[i]==1e9){
			billion[i+1]++;
			billion[i]=0;
		}
		else break;
	}
}
inline void reduce(int[] billion){
	billion[0]--;
	for(int i=0;i<25;i++){
		if(billion[i]<0){
			billion[i]=1e9-1;
			billion[i+1]--;
		}
		else break;
	}
}
int mx[5]={1,0,-1,0};
int my[5]={0,-1,0,1};
void dfs(int o){
	for(int i=0;i<f[o].m&&flag;i++){
		//printf("%d %d\n",x,y);
		if(f[o].c[i][0]=='G'){
			x+=mx[dir];
			y+=my[dir];
			ans=max(ans,abs(x)+abs(y));
		}
		else if(f[o].c[i][0]=='L'){
			if(dir==0)dir=3;
			else dir--;
		}
		else if(f[o].c[i][0]=='R'){
			if(dir==3)dir=0;
			else dir++;
		}
		else {
			int tmp=f[o].c[i][1]-'0';
			if(mark[tmp]==1){
				if(!first){
					tmpx=x;
					tmpy=y;
					first=tmp;
				}
				else if(first){
					if(tmp==first)flag--;
				}
			}
			if(flag){
				mark[tmp]=1;
				//printf("%d\n",tmp);
				dfs(tmp);
				mark[tmp]=0;
			}
		}
	}
	return;
}
int main(){
	//freopen("in.txt","r",stdin);
	int n;
	while(scanf("%d",&n)==1){
		first=ans=x=y=dir=tmpx=tmpy=0;
		flag=4;
		for(int i=1;i<=n;i++){
			scanf("%d%*c",&f[i].m);
			for(int j=0;j<f[i].m;j++)
				scanf("%s",f[i].c[j]);
		}
		for(int i=0;i<n;i++)
			f[0].c[i][1]=i+'0'+1;
		f[0].m=n;
		dfs(0);
		if(flag)printf("%d\n",ans);
		else if(x==tmpx&&y==tmpy)printf("%d\n",ans);
		else puts("Infinity");
		memset(f,0,sizeof(f));
		memset(mark,0,sizeof(mark));
	}
	return 0;
}
