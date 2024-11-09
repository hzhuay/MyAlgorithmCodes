#include<cstdio>
#include<cstring> 
bool a[305];
int main(){
	int n,p,m;
	while(scanf("%d%d%d",&n,&p,&m),n!=0){
		memset(a,0,sizeof(a));
		int count=0;
		while(count!=n){
			int point=1;
			while(point<=m){
				if(!a[p%n])point++;
				p++;
			}
			a[(p-1)%n]=1;
			count++;
			printf("%d%c",(p-1)%n?(p-1)%n:n,",\n"[count==n]);	
		}
	}
	return 0;
}
