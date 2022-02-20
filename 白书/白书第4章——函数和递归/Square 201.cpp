#include<cstdio>
#include<cstring>
int s[10][10],ans[10];
int main(){
	//freopen("in.txt","r",stdin);
	int kase=0,n,m,x,y;
	char c;
	while(scanf("%d",&n)!=EOF){
		if(kase++)printf("\n**********************************\n\n");
		printf("Problem #%d\n\n",kase);
		scanf("%d",&m);
		while(m--){
			scanf("\n%c %d %d",&c,&x,&y);
			if(c=='H')s[x][y]++;//H=1;V=2;H&V=3
			else s[y][x]+=2;
		}
		for(int k=1;k<=n;k++){
			int tem=n-k;
			for(int i=1;i<=tem;i++)
				for(int j=1;j<=tem;j++){
					if(s[i][j]==3){
						bool mark=1;
						for(int q=i+1;q<=i+k-1;q++)
							if(s[q][j]==0||s[q][j]==1)mark=0;
						for(int q=j+1;q<=j+k-1;q++)
							if(s[i][q]==0||s[i][q]==2)mark=0;
						for(int q=i;q<=i+k-1;q++)
							if(s[q][j+k]==0||s[q][j+k]==1)mark=0;
						for(int q=j;q<=j+k-1;q++)
							if(s[i+k][q]==0||s[i+k][q]==2)mark=0;
						if(mark)ans[k]++;
					}
				}
		}
		bool flag=0;
		for(int i=1;i<=9;i++)
			if(ans[i]){
				printf("%d square (s) of size %d\n",ans[i],i);
				flag=1;
			}
		if(!flag)puts("No completed squares can be found.");
		memset(ans,0,sizeof(ans));
		memset(s,0,sizeof(s));
		
	}
	return 0;
}
