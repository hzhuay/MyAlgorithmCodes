#include<cstdio>
#include<cstring>
#define M 15
int lim[M],p[M],two[M]={1,2,4,8,16,32,64,128,256,512,1024};
bool mark[M][M];
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int kase=1,n;
	while(scanf("%d",&n),n!=0){
		int a,b,i;
		bool ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a,&b,&p[i]);
			p[i]--;
			lim[i]=a+b;
			for(int j=0;j<a;j++)mark[i][j]=1;
		}
		for(i=1;i<=1000;i++){//决定下一时刻的状态 
			bool flag=1;
			for(int j=1;j<=n&&flag;j++)
				if(!mark[j][p[j]])
					flag=0;
			if(flag){
				ans=1;
				break;
			}
			bool pi[M]={0};
			for(int j=1;j<=n;j++){
				if(mark[j][p[j]]&&!mark[j][p[j]+1]){
					int awake=0;
					for(int k=1;k<=n;k++)
						if(mark[k][p[k]])awake++;
					if(awake>=n-awake)pi[j]=1;
				}
			}
			for(int j=1;j<=n;j++){
				if(pi[j])p[j]=0;
				else p[j]=(p[j]+1)%lim[j];
			}
			//printf("%d: ",i+1);for(int j=1;j<=n;j++)printf("%d ",mark[j][p[j]]);puts("");
		}
		if(ans)printf("Case %d: %d\n",kase++,i);
		else printf("Case %d: -1\n",kase++);
		memset(lim,0,sizeof(lim));
		memset(p,0,sizeof(p));
		memset(mark,0,sizeof(mark));
	}
	return 0;
}
