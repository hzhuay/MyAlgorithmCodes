#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char str[25][50];
int cnt[25][25],len[25],mark[25],n,final;
int count(int x,int y){
	int sh=len[x]<len[y]?x:y,i;
	for(i=1;i<=len[sh];i++){
		bool mark=true;
		for(int j=0;j<i;j++){
			if(str[x][len[x]-i+j]!=str[y][j]){
				mark=false;
				break;
			}
		}
		if(mark)break;
	}
	if(i-1==len[sh])return 0;
	else return i;
}
void dfs(int x,int ans){
	for(int i=0;i<n;i++){
		if(cnt[x][i]&&mark[i]){
			mark[i]--;
			final=max(final,ans+len[i]-cnt[x][i]);
			dfs(i,ans+len[i]-cnt[x][i]);
			mark[i]++;
		}
	}
}
int main(){
	char start;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s\n",str[i]);
		len[i]=strlen(str[i]);
		mark[i]=2;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			cnt[i][j]=count(i,j);
//			printf("%d%c",cnt[i][j]," \n"[j==n-1]);
		}
	scanf("%c",&start);
	for(int i=0;i<n;i++)
		if(str[i][0]==start){
			mark[i]--;
			final=max(final,len[i]);
			dfs(i,len[i]);
			mark[i]++;
		}			
	printf("%d",final);
	return 0;
}
