#include<cstdio>
int main(){
	int n=0;
	char c;
	while(c=getchar(),c!='@'){
		if(c=='(')n++;
		else if(c==')')n--;
		if(n<0){
			printf("NO");
			return 0;	
		}
	}
	if(n!=0)printf("NO");
	else printf("YES");
	return 0;
}
