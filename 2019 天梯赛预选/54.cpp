#include<bits/stdc++.h>
using namespace std;
char str[105][105],ans[105][105];
int main(){
	char c;
	int n;
	bool flag=true;
	scanf("%c %d",&c,&n);
	cin.getline(str[0],105);
	for(int i=0;i<n;i++)
		cin.getline(str[i],105);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			if(str[n-1-i][n-1-j]==' ')ans[i][j]=' ';
			else ans[i][j]=c;
			if(str[i][j]!=str[n-1-i][n-1-j])flag=false;
		}
	if(flag)printf("bu yong dao le\n");
	for(int i=0;i<n;i++)
		printf("%s\n",ans[i]);
	return 0;
}
