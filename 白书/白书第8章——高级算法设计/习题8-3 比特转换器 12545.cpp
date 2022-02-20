#include<cstdio>
#include<cstring>
char fr[105],to[105];
int main(){
//	freopen("in.txt","r",stdin);
	int kase,T=1;
	scanf("%d",&kase);
	while(T<=kase){
		scanf("%s%s",fr,to);
		int len=strlen(fr),n=0,ans=0;//n为to比fr多几个1 
		for(int i=0;i<len;i++){
			if(fr[i]=='1')n--;
			if(to[i]=='1')n++;
		}
		
		if(n<0){//fr的1比to多 
			printf("Case %d: -1\n",T++);
			continue;
		}
			
		for(int i=0;i<len;i++){
			if(fr[i]=='?'){
				if(to[i]=='1'&&n){
					fr[i]='1';
					n--;
				}else fr[i]=0;
				ans++; 
			}
		}
		
		for(int i=0;i<len&&n!=0;i++)
			if(fr[i]=='0'&&to[i]=='1'){
				fr[i]='1';
				ans++;
				n--;	
			} 
		
		for(int i=0;i<len;i++)
			if(fr[i]=='1'&&to[i]=='0')ans++;
		printf("Case %d: %d\n",T++,ans);
		memset(fr,0,sizeof(fr));
		memset(to,0,sizeof(to));
	}
	return 0;
} 
