#include<cstdio>
using namespace std;
int ans[250000],num[1000005];
int gcd(int a,int b){return b==0?a:gcd(b,a%b);} 
int main(){
	int a,b,c,p=0;
	for(int i=1;i<500;i++){
		for(int j=i+1;2*j*(i+j)<=1000000;j+=2){
			if(gcd(i,j)!=1)continue;
			a=j*j-i*i;
			b=2*i*j;
			if(a>b){int tmp=a;a=b;b=tmp;}//Ï£Íûa<b 
			c=j*j+i*i;
			ans[p++]=a+b+c;
		}
	}
	//printf("%d\n",p);
	for(int i=0;i<p;i++){
		int j=1;
		while(ans[i]*j<=1000000){
			num[ans[i]*j]++;
			j++;
		}
	}
	
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		int cnt=0,x=0;
		for(int i=n;i<=m;i++)
			if(cnt<num[i]){
				cnt=num[i];
				x=i;
			}
		printf("%d %d\n",x,cnt);
	}
	return 0;
}
