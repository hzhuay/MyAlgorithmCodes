#include<cstdio>
char q[100005];
int main(){
	//freopen("in.txt","r",stdin);
	int n,d;
	while(scanf("%d%d",&n,&d)&&n){
		getchar();
		int f=-1,r=-1;
		for(int i=0;i<n;i++){
			char c=getchar();
			while(r!=f&&q[r]<c)r--;
			q[++r]=c;
			if(i>d-1)printf("%c",q[++f]);
		}
		puts("");
	}
	return 0;
}
