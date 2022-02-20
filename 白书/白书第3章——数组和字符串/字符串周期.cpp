#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char str[85];
int per[15];
int main(){
	int kase,len,j=0,lenp,i;
	bool mark;
	cin>>kase;
	while(kase--){
		scanf("%s",str);
		len=strlen(str);
		j=0;
		for(i=1;i<=len;i++)
			if(len%i==0)per[j++]=i;
		for(i=0;per[i]!=0;i++){
			mark=true;
			for(j=0;j<len;j++){
				if(str[j]!=str[j%per[i]])mark=false;
			}
			if(mark)break;
		}
		printf("%d\n",per[i]);
		if(kase!=0)printf("\n");
	}
	return 0;
}
