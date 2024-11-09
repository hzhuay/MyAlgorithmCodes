#include<cstdio>
#include<algorithm>
using namespace std;
int n[10000],cnt=2;
bool mark[50][50][50][50];
void dfs(int a,int b,int c,int d,int x){
	if(x<=1000000000&&!mark[a+1][b][c][d]){
		n[cnt++]=x*2;
		mark[a+1][b][c][d]=1;
		//printf("%d %d %d %d %d\n",a+1,b,c,d,x*2);
		dfs(a+1,b,c,d,x*2);
	}
	if(x<=666666667&&!mark[a][b+1][c][d]){
		n[cnt++]=x*3;
		mark[a][b+1][c][d]=1;
		//printf("%d %d %d %d %d\n",a,b+1,c,d,x*3);
		dfs(a,b+1,c,d,x*3);
	}
	if(x<=400000000&&!mark[a][b][c+1][d]){
		n[cnt++]=x*5;
		mark[a][b][c+1][d]=1;
		//printf("%d %d %d %d %d\n",a,b,c+1,d,x*5);
		dfs(a,b,c+1,d,x*5);
	}
	if(x<=285714286&&!mark[a][b][c][d+1]){
		n[cnt++]=x*7;
		mark[a][b][c][d+1]=1;
		//printf("%d %d %d %d %d\n",a,b,c,d+1,x*7);
		dfs(a,b,c,d+1,x*7);
	}
} 
int main(){
	n[1]=1;
	dfs(0,0,0,0,1);
	sort(n+1,n+cnt);
	//for(int i=1;i<cnt;i++)printf("%d\n",n[i]);
	int res;
	while(scanf("%d",&res),res!=0){
		if(res%10==1&&res%100!=11)
            printf("The %dst humble number is %d.\n",res,n[res]);
        else if(res%10==2&&res%100!=12)
            printf("The %dnd humble number is %d.\n",res,n[res]);
        else if(res%10==3&&res%100!=13)
            printf("The %drd humble number is %d.\n",res,n[res]);
        else
            printf("The %dth humble number is %d.\n",res,n[res]);
	}
	return 0;
}
