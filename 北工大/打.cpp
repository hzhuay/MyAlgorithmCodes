#include<cstdio>
int h,w,H,W;
bool check(){
	if(4*h*w>H*W)return false;
	return true;
}
int main(){
	scanf("%d%d%d%d",&h,&w,&H,&W);
	if(check())puts("Neng");
	else puts("BuNeng");
}
