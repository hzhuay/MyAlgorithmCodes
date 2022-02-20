#include<cstdio>
#include<cstring>
using namespace std;
int n,L,cnt,S[85]; 
int dfs(int cur){
	if(cnt++==n){
		for(int i=0;i<cur;i++){
			printf("%c",'A'+S[i]);
			if(i==cur-1){puts("");break;}//修改后的 
			if((i+1)%4==0){
				if(i==63)puts("");
				else printf(" ");
			}
		}
		//if(cur!=64)puts("");//原代码 
		printf("%d\n",cur);
		return 0;
	}
	for(int i=0;i<L;i++){
		S[cur]=i;
		int ok=1;
		for(int j=1;j*2<=cur+1;j++){
			int equal=1;
			for(int k=0;k<j;k++)
				if(S[cur-k]!=S[cur-k-j]){
					equal=0;
					break;
				}
			if(equal){
				ok=0;break;
			}
		}
		if(ok)if(!dfs(cur+1))return 0;
	}
	return 1;
}
int main(){
	//freopen("in.txt","r",stdin);
	while(scanf("%d%d",&n,&L),n!=0){
		memset(S,0,sizeof(S));
		cnt=0;
		dfs(0);
	}
	return 0;
}
