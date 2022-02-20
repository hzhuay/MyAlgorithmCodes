#include<cstdio>
#include<cstring>
int res[105][105];
int main(){
	int t,n,m;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&m,&n);
		int ans=0;
		for(int c=0;c<=m;c++)
			for(int b=0;b<=c;b++)
				for(int a=0;a<=b;a++)
					if(a!=0&&b!=c&&a*a+b*b==c*c)ans++;
		
		ans+=(n-1)*(m+1);		
		printf("%d\n",ans);
	}
	return 0;
}
