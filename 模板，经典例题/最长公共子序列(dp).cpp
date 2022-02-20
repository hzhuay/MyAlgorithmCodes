#include<cstdio>
#include<algorithm>
#include<cstring>
#define M 205
using namespace std;
int maxlen[M][M];
char s1[M],s2[M];
int main(){
	int len1,len2,i,j;
	while(scanf("%s %s",s1,s2)!=EOF){
		len1=strlen(s1);
		len2=strlen(s2);
		for(i=0;i<=len1;i++)maxlen[i][0]=0;
		for(j=0;j<=len2;j++)maxlen[0][j]=0;
		for(i=1;i<=len1;i++)
			for(j=1;j<=len2;j++){
				if(s1[i-1]==s2[j-1])maxlen[i][j]=maxlen[i-1][j-1]+1;
				else maxlen[i][j]=max(maxlen[i][j-1],maxlen[i-1][j]);
			}
		printf("%d\n",maxlen[len1][len2]);
	}
	return 0;
}
