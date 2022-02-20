#include<bits/stdc++.h>
inline int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
inline int lcm(int a,int b){return a/gcd(a,b)*b;}
int dis[300];
int main(){
	int x,y,ans=0,cnt=0;
	scanf("%d%d",&x,&y);
	for(int i=x;i<=y;i++)
		if(y%i==0)dis[cnt++]=i;
	for(int i=0;i<cnt;i++){
		for(int j=0;j<=i;j++){
			if(lcm(dis[i],dis[j])==y&&gcd(dis[i],dis[j])==x){
				ans+=dis[i]==dis[j]?1:2;
				continue;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
