#include<cstdio>
char str[20];
int main(){
	scanf("%s",str);
	int t=1,sum=0;
	for(int i=0;i<=10;i++)
		if(str[i]!='-')sum+=(str[i]-'0')*t++;
	sum%=11;
	if(sum==str[12]-'0'||(sum==10&&str[12]=='X'))puts("Right");
	else{
		if(sum==10)str[12]='X';
		else str[12]=sum+'0';
		printf("%s",str);
	}
	return 0;
}
