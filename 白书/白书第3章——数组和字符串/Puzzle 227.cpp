#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
using namespace std;
char seq[7][7];
int mi[]={1,0,-1,0},mj[]={0,1,0,-1},hash[100];
bool Ipt(){
	char c;
	int t=0;
	while(c=getchar(),!isalnum(c)&&c!=' ');
	if(c=='Z')return 0;
	while(1){
		seq[t/5][t%5]=c;
		t++;
		if(t>=25)break;
		while(c=getchar(),!isalnum(c)&&c!=' ');
	}
	return 1;
}
int main(){
	//freopen("test.in","w",stdout);
	int i=1,j=1,x,y,kase=1;
	char op;
	bool flag=false,mark;
	memset(hash,-1,sizeof(hash));
	hash['B']=0;
	hash['R']=1;
	hash['A']=2;
	hash['L']=3;
	while(Ipt()){
		if(flag)puts("");
		flag=true;
		mark=true;
		printf("Puzzle #%d:\n",kase++);
		for(i=0;i<5;i++)
			for(j=0;j<5;j++)
				if(seq[i][j]==' '){
					x=i;
					y=j;
				}
		op=getchar();
		while(op!='0'){
			if(op=='\n'){
				op=getchar();
				continue;
			}
			else if(hash[op]==-1){
				puts("This puzzle has no final configuration.");
				mark=false;
				while((op=getchar())!=48);
				break;
			}
			else if(0<=x+mi[hash[op]]&&5>x+mi[hash[op]]&&0<=y+mj[hash[op]]&&5>y+mj[hash[op]]){
				swap(seq[x][y],seq[x+mi[hash[op]]][y+mj[hash[op]]]);
				x+=mi[hash[op]];
				y+=mj[hash[op]];
			}
			else{
				puts("This puzzle has no final configuration.");
				mark=false;
				while((op=getchar())!=48);
				break;
			}
		op=getchar();
		}
		if(mark)for(i=0;i<5;i++)
			for(j=0;j<5;j++)
				printf("%c%c",seq[i][j]," \n"[j==4]);
	}
	return 0;
}
