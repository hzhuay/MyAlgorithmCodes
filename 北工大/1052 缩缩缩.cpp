#include<cstdio>
#include<cstring>
char str[105];
int main(){
	int kase,len;
	scanf("%d",&kase);
	while(kase--){
		scanf("%s",str);
		len=strlen(str);
		if(len>10)printf("%c%d%c\n",str[0],len-2,str[len-1]);
		else printf("%s\n",str);
	}
	return 0;
}
