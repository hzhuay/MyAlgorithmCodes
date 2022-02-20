#include<iostream>
#include<cstring>
#include<string>
#include<sstream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxr=1000;
const int maxs=185;
const int maxc=85;
char str[maxr][maxs][maxc];
int len[maxs];
int c[maxr];
int main(){
	/*freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);*/
	string line;
	int i,j,k,r;
	for(r=0;getline(cin,line);r++){
		stringstream ss(line);
		for(j=0;ss>>str[r][j];j++)
			if(len[j]<int(strlen(str[r][j])))len[j]=strlen(str[r][j]);
		c[r]=j;
	}
	for(i=0;i<r;i++){
		for(j=0;j<c[i];j++){
			int left=(len[j]-strlen(str[i][j]));
			printf("%s",str[i][j]);
			if(j!=c[i]-1)for(k=0;k<=left;k++)putchar(' ');
		}
		puts("");
	}
	return 0;
}
