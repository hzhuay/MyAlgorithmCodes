#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s1[105],s2[105];
int main(){
//	freopen("in.txt","r",stdin);
	int T,kase=1;
	scanf("%d",&T);
	while(T--){
		scanf("%s%s",s1,s2);
		int a=0,b=0,c=0,d=0,ans=-1,len=strlen(s1);
		for(int i=0;i<len;i++){
			if(s1[i]=='1'&&s2[i]=='0')a++;
			else if(s1[i]=='?'&&s2[i]=='0')b++;
			else if(s1[i]=='0'&&s2[i]=='1')c++;
			else if(s1[i]=='?'&&s2[i]=='1')d++;
		}
		if(a<=c+d){
			//b+=max(a-c,0);
			//d-=max(a-c,0);
			c=max(c-a,0);
			ans=a+b+c+d;
		}
		printf("Case %d: %d\n",kase++,ans);
	}
	return 0;
}
