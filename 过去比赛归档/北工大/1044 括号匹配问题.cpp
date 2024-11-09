#include<cstdio>
#include<cstring>
#define M 105
char str[M],ans[M];
int left[M],right[M];
int main(){
	int i,r,l;
	//freopen("in.txt","r",stdin);
	while(scanf("%s",str)!=EOF){
		r=0;
		l=0;
		int len=strlen(str);
		for(i=0;i<len;i++){
			if(str[i]==')'){
				if(l){
					left[--l]=0;
				}else {
					right[r++]=i;
				}
			}
			else if(str[i]=='('){
				left[l++]=i;
			}
		}
		for(i=0;i<r;i++)ans[right[i]]='?';
		for(i=0;i<l;i++)ans[left[i]]='$';
		for(i=0;i<len;i++)if(!ans[i])ans[i]=' ';
		printf("%s\n",str);
		for(i=0;i<len;i++)putchar(ans[i]);
		puts(""); 
		memset(left,0,sizeof(left));
		memset(right,0,sizeof(right));
		memset(str,0,sizeof(str));
		memset(ans,0,sizeof(ans));
	}
	return 0;
}
