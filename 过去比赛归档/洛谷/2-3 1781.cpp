#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct String{
	int num,len;
	char str[105];
}s[25];
bool cmp(String s1,String s2){
	if(s1.len!=s2.len)return s1.len>s2.len;
	else{
		int len=s1.len;
		for(int i=0;i<len;i++)
			if(s1.str[i]!=s2.str[i])return s1.str[i]>s2.str[i];
	}
	return true;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		s[i].num=i+1;
		scanf("%s",s[i].str);
		s[i].len=strlen(s[i].str);
	}
	sort(s,s+n,cmp);
	printf("%d\n",s[0].num);
	printf("%s",s[0].str);
	return 0;
}
