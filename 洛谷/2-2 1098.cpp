#include<cstdio>
#include<cstring>
char str[105],map[5][130];
inline bool isNum(char c){return c>='0'&&c<='9';}
inline bool isLet(char c){return c>='a'&&c<='z';}
inline bool isSame(char a,char b){return (isNum(a)&&isNum(b))||(isLet(a)&&isLet(b));}
int main(){
	for(int i='0';i<='9';i++){
		map[1][i]=map[2][i]=i;
		map[3][i]='*';
	}
	for(int i='a';i<='z';i++){
		map[1][i]=i;
		map[2][i]=i-('a'-'A');
		map[3][i]='*';
	}
	
	int p1,p2,p3,len;
	char l,r;
	scanf("%d %d %d\n%s",&p1,&p2,&p3,str);
	len=strlen(str);
	putchar(str[0]);
	for(int i=1;i<len-1;i++){
		if(str[i]=='-'&&isSame(str[i-1],str[i+1])){
			if(str[i+1]-str[i-1]==1)continue;
			else if(str[i+1]<=str[i-1]){
				putchar('-');
			}else {//str[i+1]-str[i-1]>1)
				if(p3==2)p3=-1;
				l=str[i-p3];
				r=str[i+p3];
				for(int i=l+p3;i!=r;i+=p3)	
					for(int j=0;j<p2;j++)
						putchar(map[p1][i]);
			}
		}else putchar(str[i]);
	}
	if(len>1)putchar(str[len-1]);
	return 0;
}
