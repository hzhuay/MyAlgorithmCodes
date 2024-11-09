#include<cstdio>
#include<cstring>
int mon[15]={31,28,31,30,31,30,31,31,30,31,30,31};
int month[2][15],dpy[2];
char date[10];
int isleap(int year){
	if(year%400==0)return 1;
	if(year%100!=0&&year%4==0)return 1;
	return 0;
}
int main(){
	//freopen("in.txt","r",stdin);
	memcpy(month[0],mon,sizeof(mon));
	memcpy(month[1],mon,sizeof(mon));
	month[1][1]=29;
	dpy[1]=366;dpy[0]=365;
	int y,m,d,day[2],T=2;
	while(T--){
		int i=1900;
		scanf("%s",date);
		y=(date[0]-48)*1000+(date[1]-48)*100+(date[2]-48)*10+(date[3]-48);
		m=(date[5]-48)*10+(date[6]-48);
		d=(date[8]-48)*10+(date[9]-48);
		while(i<y)
			d+=dpy[isleap(i++)];
		for(int j=0;j<m-1;j++)
			d+=month[isleap(y)][j];
		day[T]=d;
	}
	if(day[1]>day[0])puts("liang qing ruo shi jiu chang shi you qi zai zhao zhao mu mu");
	else printf("%d",day[0]-day[1]);
	return 0;
}
