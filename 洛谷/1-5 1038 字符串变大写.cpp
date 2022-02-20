#include<cstdio>
#include<cstring>
inline char tolow(char c){return c>='A'&&c<='Z'?c+32:c;}
char fr[100],to;
int main(){
//	freopen("testdata (7).in","r",stdin);
//	freopen("in2.txt","r",stdin);
//	freopen("out1.txt","w",stdout);
	int ans=0,ini=-1,cnt=0,len,p=0,cur=0;
	bool flag=true;
	scanf("%s%*c",fr);
	len=strlen(fr);
	fr[len++]=' ';
	for(int i=0;i<len;i++)fr[i]=tolow(fr[i]);
	while(to=getchar(),to!=EOF){
		to=tolow(to);
		if(fr[p]==to&&flag)p++;
		else{
			p=0;
			flag=false;
		}
		if(to==' '&&p==len&&flag){
			ans++;
			p=0;
			if(ini==-1){
				ini=cur;
			}
		}		
		cnt++;
		if(to==' '){
			cur+=cnt;
			cnt=0;
			flag=true;
		}	
	}
	if(ans==0)puts("-1");
	else printf("%d %d",ans,ini); 
	return 0;
}
