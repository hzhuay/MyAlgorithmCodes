#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int x[15][15],org[15][15],plusr[10],R,C;
int cube[10]={1,3,9,27,81,243,729,2187,6561,19683};
void op(int o,int k){
	if(o==1){
		for(int j=0;j<C;j++){//操作每行 
			x[k][j]++;
			x[k][j]%=3;
		}
	}else{
		for(int i=0;i<R;i++){//操作每列 
			x[i][k]++;
			x[i][k]%=3;
		}
	}
}

void debug(){
	char o[5];
	while(scanf("%s",o),o[0]!='0'){
		if(o[0]=='r')op(1,o[1]-'0'-1);
		else if(o[0]=='c')op(0,o[1]-'0'-1);
		puts("");
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++)
				printf("%d ",x[i][j]);
			puts("");
		}
	}
}
int check(int c){
	int tmp=0;
	for(int i=0;i<R;i++)
		if(x[i][c]==0)tmp++;
	return tmp;
}
int main(){
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&R,&C);
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++){
			int tmp;
			scanf("%d",&tmp);
			org[i][j]=tmp%3;
		}

	/*for(int i=0;i<R;i++){
		for(int j=0;j<C;j++)
			printf("%d ",x[i][j]);
		puts("");
	}*/
	//debug();
	int maxans=0;
	for(int i=0;i<cube[R];i++){
		memset(plusr,0,sizeof(plusr));
		memcpy(x,org,sizeof(org));
		int t=i;
		for(int j=R-1;j>=0;j--){
			while(t>=cube[j]){
				t-=cube[j];
				plusr[j]++;
			}
		}
		for(int r=0;r<R;r++){
			for(int k=0;k<plusr[r];k++)
				op(1,r);
		}
		
		int ans=0;
		for(int c=0;c<C;c++){
			int tmp=0;
			tmp=max(check(c),tmp);
			for(int k=0;k<2;k++){
				op(0,c);
				tmp=max(check(c),tmp);
			}
			ans+=tmp;
		}
		maxans=max(ans,maxans);
	}
	printf("%d",maxans);
	return 0;
}
