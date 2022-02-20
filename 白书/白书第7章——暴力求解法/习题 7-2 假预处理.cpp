#include<cstdio>
#include<cstring>
#include<queue>
#include<string>
using namespace std;
int fin,nfb,bx[55],by[55];
int mx[]={1,0,0,-1};
int my[]={0,1,-1,0};
char dec[]="ensw";
int num[5]={8,8,72,112};
bool vis[300][300];
char ans[5][115][20]={
	{"enwnwse","eswswne","neseswn","nwswsen","senenws","swnwnes","wnenesw","wsesenw"},
	{"enwswsen","eswnwnes","neswswne","nwsesenw","senwnwse","swnenesw","wneseswn","wsenenws"},
	{"enenwswnwswsene","enenwswswnwnese","eneswnwnwswnese","eneswswswswnene","enwneswnwseswne","enwseswswsenwne","enwswnenwsenesw","enwswseseswnwne",
	"enwswseswsenenw","esenwnwnwnwsese","esenwswswnwsene","eseswnwnwswsene","eseswnwswnwnese","eswnenwnwneswse","eswnwnenenwswse","eswnwnenwnesesw",
	"eswnwseswnesenw","eswsenwswnenwse","neneswseswswnen","neneswswsesenwn","nenwseseswsenwn","nenwswswswsenen","nesenwseswnwsen","neswnwswswnesen",
	"neswseneswnenws","neswswnwnwsesen","neswswnwswnenes","nwneseseseswnwn","nwneswswseswnen","nwnwseseswswnen","nwnwseswsesenwn","nwsenesesenwswn",
	"nwseseneneswswn","nwsesenesenwnws","nwseswnwsenwnes","nwswneswseneswn","seneswnenwswnes","senwnesenwseswn","senwnwswnwsesen","senwnwswswnenes",
	"senwswnwnwsenes","sesenwnenwnwses","sesenwnwnenesws","seswnenenwnesws","seswnwnwnwneses","swneneseneswswn","swnenesesenwnws","swnenwswneswsen",
	"swneseneneswnws","swnwsenwnesenws","swsenenenenwsws","swsenwnwnenwses","swswnenenwnwses","swswnenwnenesws","wnenwseneswsenw","wnesenwneswnwse",
	"wneseswseswnwne","wneseswswsenenw","wneswseseswnenw","wnwneseneseswnw","wnwnesesenenwsw","wnwsenenesenwsw","wnwsesesesenwnw","wsenenwnenwswse",
	"wsenenwnwnesesw","wseneswsenwswne","wsenwnenenwsesw","wseswnesenwnesw","wswneneneneswsw","wswneseseneswnw","wswseneneseswnw","wswsenesenenwsw"},
	{"enenwnwnwswsesen","enenwnwswnwsenes","enenwswnwnwneses","enenwswswswsenen","eneswnwswswnesen","eneswswnwnwsesen","eneswswnwswnenes","enwnenwnwseswsen",
	"enwneswnwnenwses","enwneswswseswnen","enwnwneneswswsen","enwnwnenwseseswn","enwnwneswnesenws","enwswneswseneswn","esenwnwswnwsesen","esenwnwswswnenes",
	"esenwswnwnwsenes","eseswnwnwnwneses","eseswnwswswsenen","eseswswnwswnesen","eseswswswnwnenes","eswnwsenwnesenws","eswsenwnwnenwses","eswsenwswseswnen",
	"eswseswswnenwnes","eswswsenwseneswn","eswswsesenwnwnes","eswswseswnenenws","neneseseswswnwne","neneseswseswnenw","neneswsesesenwnw","neneswswswswnene",
	"nenwseswswsenwne","nenwswseseswnwne","nenwswseswsenenw","neseneseswnwswne","nesenwseseneswnw","nesenwswswnwsene","nesesenenwswswne","neseseneswnwnwse",
	"nesesenwsenwnesw","neswsenwswnenwse","nwneseswseswnwne","nwneseswswsenenw","nwneswseseswnenw","nwnwsesesesenwnw","nwnwseswswswnene","nwnwswseswsenwne",
	"nwnwswswsesenenw","nwseswnesenwnesw","nwswneseseneswnw","nwswneswswnwsene","nwswnwswsenesenw","nwswswneswnenwse","nwswswnwnesesenw","nwswswnwsenenesw",
	"senenesenwswswne","seneneseswnwnwse","seneneswneswsenw","senesenenwswnwse","seneswnenesenwsw","seneswnwnwswnese","senwneswnwseswne","sesenenenwnwswse",
	"sesenenwnenwsesw","sesenwneneneswsw","sesenwnwnwnwsese","seswnenwnwneswse","seswnwnenenwswse","seswnwnenwnesesw","swnenwseneswsenw","swnwnwsenwseswne",
	"swnwnwswnesesenw","swnwnwswsenenesw","swnwsenenesenwsw","swnwsenwnwswnese","swnwswnwnesenesw","swsenenwnenwswse","swsenenwnwnesesw","swsenwnenenwsesw",
	"swswneneneneswsw","swswnenwnwnwsese","swswnwnenwneswse","swswnwnwnenesesw","wnenenwneswswsen","wnenenwnwseseswn","wnenenwsenwswnes","wnenwneneswseswn",
	"wnenwsenenwnesws","wnenwseseswsenwn","wnesenwseswnwsen","wnwneneneseswswn","wnwneneseneswnws","wnwnesenenenwsws","wnwneseseseswnwn","wnwsenesesenwswn",
	"wnwseseneneswswn","wnwsesenesenwnws","wseneswnenwswnes","wseseswneswnwsen","wseseswsenwnwnes","wseseswswnenenws","wseswnenenwnesws","wseswneseswsenwn",
	"wseswsesenwnenws","wswneneseneswswn","wswnenesesenwnws","wswneseneneswnws","wswsenenenenwsws","wswseneseseswnwn","wswsesenesenwswn","wswsesesenenwnws"}
};
inline int op(int n){return n/7+n%7-1;}
inline int change(char c){for(int i=0;i<4;i++)if(dec[i]==c)return i;}
void print(int n){
	printf("%d\n",n);
	for(int i=120;i>=100;i--){
		for(int j=100;j<=120;j++){
			int flag=1;
			for(int k=0;k<nfb;k++){
				if(j==bx[k]+110&&i==by[k]+110){flag=0;break;}
			}
			if(i==110&&j==110)printf("X");
			else if(!flag)printf("#");
			else printf("%d",vis[j][i]);
		}
		puts("");
	}
	puts("");
}
void check(int f,int n){//8 1
	int cnt=0;
	for(int i=0;i<num[n];i++){//检查第几条路线 
		int x=110,y=110;
		bool flag=1;
		memset(vis,0,sizeof(vis));
		for(int j=0;j<f;j++){//走第几步 
			for(int z=0;z<=j;z++){//一格格mark 
				x+=mx[change(ans[n][i][j])];
				y+=my[change(ans[n][i][j])];
				vis[x][y]=1;	
			}
		}
		
		//print(i);
		//printf("%s\n",ans[n][i]);
		for(int k=0;k<nfb;k++){
			if(vis[bx[k]+110][by[k]+110]){
				flag=false;
				break;
			}
		}
		if(x!=110||y!=110)flag=false;
		if(flag){
			printf("%s\n",ans[n][i]);
			cnt++;
		}
	}
	printf("Found %d golygon(s).\n\n",cnt);
}
int main(){
	//freopen("in3.txt","r",stdin);
	int kase;
	scanf("%d",&kase);
	while(kase--){
		scanf("%d%*c%d",&fin,&nfb);
		for(int i=0;i<nfb;i++){
			scanf("%d%*c%d",&bx[i],&by[i]);
		}
		/*
		for(int i=0;i<nfb;i++)
			printf("%d %d\n",bx[i],by[i]);
		*/
			
		if(fin!=7&&fin!=8&&fin!=15&&fin!=16)printf("Found 0 golygon(s).\n\n");
		else
			check(fin,op(fin));
		memset(bx,0,sizeof(bx));
		memset(by,0,sizeof(by));
	}
	return 0;
}
