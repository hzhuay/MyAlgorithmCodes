#include<cstdio>
#include<cstring>
int mon[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int month[2][15],dpy[2],year,date[10];
char date0[10],date1[10];
int isleap(int year){
	if(year%400==0)return 1;
	if(year%100!=0&&year%4==0)return 1;
	return 0;
}
int main(){
	//freopen("in.txt","r",stdin);
	memcpy(month[0],mon,sizeof(mon));
	memcpy(month[1],mon,sizeof(mon));
	month[1][2]=29;
	dpy[1]=366;dpy[0]=365;
	int y0,m0,d0,y1,m1,d1,ans=0;
	scanf("%s",date0);
	scanf("%s",date1);
	y0=(date0[0]-48)*1000+(date0[1]-48)*100+(date0[2]-48)*10+(date0[3]-48);
	m0=(date0[4]-48)*10+(date0[5]-48);
	d0=(date0[6]-48)*10+(date0[7]-48);
	y1=(date1[0]-48)*1000+(date1[1]-48)*100+(date1[2]-48)*10+(date1[3]-48);
	m1=(date1[4]-48)*10+(date1[5]-48);
	d1=(date1[6]-48)*10+(date1[7]-48);
	for(int i=0;i<8;i++)date[i]=date0[i]-48;
	if(y0==y1){
		if(m0==m1){
			for(int i=d0;i<=d1;i++){
				date[6]=i/10;date[7]=i%10;
				for(int p=0;p<=5;p++){
					if(date[p]-date[p+1]==date[p+1]-date[p+2]){ans++;break;}
				}
			}
		}else {//m0!=m1
			for(int i=d0;i<=month[isleap(y0)][m0];i++){
				date[6]=i/10;date[7]=i%10;
				for(int p=0;p<=5;p++){
					if(date[p]-date[p+1]==date[p+1]-date[p+2]){ans++;break;}
				}
			}
			for(int j=m0+1;j<m1;j++){
				date[4]=j/10;date[5]=j%10;
				for(int i=1;i<=month[isleap(y0)][j];i++){
					date[6]=i/10;date[7]=i%10;
					for(int p=0;p<=5;p++){
						if(date[p]-date[p+1]==date[p+1]-date[p+2]){ans++;break;}
					} 
				}
			}
			for(int i=1;i<=d1;i++){
				date[6]=i/10;date[7]=i%10;
				for(int p=0;p<=5;p++){
					if(date[p]-date[p+1]==date[p+1]-date[p+2]){ans++;break;}
				} 
			}
		}
	}else{//y0!=y1
		for(int i=m0;i<=12;i++){
			date[4]=i/10;date[5]=i%10;
			int r=i==m0?d0:1;
			for(int j=r;j<=month[isleap(y0)][i];j++){
				date[6]=j/10;date[7]=j%10;
				for(int p=0;p<=5;p++){
					if(date[p]-date[p+1]==date[p+1]-date[p+2]){ans++;break;}
				}
			}
		}
		for(int k=y0+1;k<y1;k++){
			date[0]=k/1000;date[1]=(k/100)%10;date[2]=(k/10)%10;date[3]=k%10;
			for(int i=1;i<=12;i++){
				date[4]=i/10;date[5]=i%10;
				for(int j=1;j<=month[isleap(k)][i];j++){
					date[6]=j/10;date[7]=j%10;
					for(int p=0;p<=5;p++){
						if(date[p]-date[p+1]==date[p+1]-date[p+2]){ans++;break;}
					}
				}
			}
		}
		date[0]=y1/1000;date[1]=(y1/100)%10;date[2]=(y1/10)%10;date[3]=y1%10;
		for(int i=1;i<=m1;i++){
			date[4]=i/10;date[5]=i%10;
			int r=i==m1?d1:month[isleap(y1)][i];
			for(int j=1;j<=r;j++){
				date[6]=j/10;date[7]=j%10;
				for(int p=0;p<=5;p++){
					if(date[p]-date[p+1]==date[p+1]-date[p+2]){ans++;break;}
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}
