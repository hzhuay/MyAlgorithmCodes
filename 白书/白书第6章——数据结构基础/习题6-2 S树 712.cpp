#include<cstdio>
#include<cstring>
#include<iostream>
#include<string> 
using namespace std;
int d[8],x[8];
int f[12]={0,1,2,4,8,16,32,64,128,256};
int leaves[260];
int ans[8];
int main(){
	//freopen("in.txt","r",stdin);
	int n,kase=1;
	char str[25];
	while(scanf("%d",&n),n!=0){
		printf("S-Tree #%d:\n",kase++);
		int tmp=0,m;
		for(int i=0;i<n;i++){
			scanf("%s",str);
			d[i]=str[1]-48;
		}
		int r=f[n+1],cnt=0;
		for(int i=0;cnt<r;i++){
			char c;
			c=getchar();
			if(c!='\n'){
				leaves[cnt]=c-48;
				cnt++;
			}
		}
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			tmp=0;
			scanf("%s",str);
			for(int j=1;j<=n;j++){
				x[j]=str[j-1]-48;
			}
			for(int k=0;k<n;k++){
				if(x[d[k]])tmp+=f[n-k];
			}	
			ans[i]=leaves[tmp];
		}
		for(int i=0;i<m;i++)
			printf("%d",ans[i]);
		printf("\n\n");
		memset(x,0,sizeof(x));
		memset(d,0,sizeof(d));
		memset(ans,0,sizeof(ans));
		memset(leaves,0,sizeof(leaves));
	}
	
	return 0;
}
