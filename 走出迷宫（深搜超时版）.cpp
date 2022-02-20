#include<cstdio>
#include<cstring>
#define M 105
char str[M][M];
int mx[5]={1,0,-1,0},my[5]={0,1,0,-1},ans=0;
void sch(int x,int y,int t,int ox,int oy){
	for(int i=0;i<4;i++)
		if(!((x+mx[i])==ox&&(y+my[i])==oy)&&str[x+mx[i]][y+my[i]]=='.')
			sch(x+mx[i],y+my[i],t+1,x,y);
		else if(str[x+mx[i]][y+my[i]]=='T'){printf("%d\n",t);return;}
}
int main(){
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%s",str[i]+1);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(str[i][j]=='S'){
				sch(i,j,1,0,0);
				return 0;
			}
	return 0;
}
