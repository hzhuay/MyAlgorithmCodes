#include<cstdio>
struct squre{
	int x,y,l,h;
}s[10005];
int main(){
	int n,x,y,ans=-1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d%d",&s[i].x,&s[i].y,&s[i].l,&s[i].h);
	scanf("%d%d",&x,&y);
	for(int i=n;i>0;i--)
		if(x>=s[i].x&&x<=s[i].x+s[i].l&&y>=s[i].y&&y<=s[i].y+s[i].h){
			ans=i;
			break;
		}
	printf("%d",ans);
	return 0;
}
