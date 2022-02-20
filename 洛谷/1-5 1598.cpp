#include<cstdio>
#include<cstring>
char str[105];
int cnt[150];
int main(){
	int max=0;
	while(scanf("%s",str)!=EOF){
		int len=strlen(str);
		for(int i=0;i<len;i++)
			if(str[i]>='A'&&str[i]<='Z')cnt[str[i]]++;	
	}
	for(int i='A';i<='Z';i++)
		if(max<cnt[i])max=cnt[i];
	for(int i=max;i>0;i--)
		for(int j='A';j<='Z';j++){
			if(cnt[j]>=i)printf("*");
			else printf(" ");
			printf("%c"," \n"[j=='Z']);
		}
	for(int i='A';i<='Z';i++)printf("%c%c",i," "[i=='Z']);
	return 0;
}
