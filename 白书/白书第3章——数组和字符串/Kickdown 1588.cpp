#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
char a[2][205];
int main(){
	//freopen("test.out","w",stdout);
	int i,j,len[2],mark,ans,ans2;
	bool flag;
	memset(a[0],0,sizeof(a[0]));
	memset(a[1],0,sizeof(a[1]));
	while(scanf("%s %s",a[0],a[1])!=EOF){
		len[0]=strlen(a[0]);
		len[1]=strlen(a[1]);
		if(len[0]>len[1])mark=0;
		else mark=1;
		for(i=0;i<len[mark];i++){
			flag=true;
			for(j=0;j<len[!mark]&&flag;j++){
				if(a[mark][j+i]==0)break;
				if(a[!mark][j]+a[mark][j+i]-96>3)flag=false;
			}
			if(flag)break;
		}
		if(i==len[mark])ans=len[mark]+len[!mark];
		else if(len[!mark]+i<len[mark])ans=len[mark];
		else ans=len[!mark]+i;
		
		for(i=0;i<len[!mark];i++){
			flag=true;
			for(j=0;j<len[mark]&&flag;j++){
				if(a[!mark][j+i]==0)break;
				else if(a[mark][j]+a[!mark][j+i]-96>3)flag=false;
			}
			if(flag)break;
		}
		if(i==len[!mark])ans2=len[mark]+len[!mark];
		else ans2=len[mark]+i;
		printf("%d\n",min(ans,ans2));
		memset(a[0],0,sizeof(a[0]));
		memset(a[1],0,sizeof(a[1]));
	}
	return 0;
}
