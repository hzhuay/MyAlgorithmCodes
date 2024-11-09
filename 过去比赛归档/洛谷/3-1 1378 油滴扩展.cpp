#include<cstdio>
#include<cmath>
#define Pi 3.1415926535
int n;
double x,X,y,Y,ans;
struct Circle{
	double x,y,r;
	bool vis;
}c[6];
void swap(double* a,double* b){double c=*a;*a=*b;*b=c;}
int roundoff(double a){return a>0?(int)(a*2+1)/2:(int)(a*2-1)/2;}
inline double small(double a,double b){return a<b?a:b;}
inline double dist(Circle a,Circle b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
void dfs(int cnt,double cur){
	if(cnt==n){
		if(ans<cur)ans=cur;
		return;
	}
	for(int i=0;i<n;i++){
		if(!c[i].vis){
			double &r=c[i].r;
			r=small(c[i].x-x,X-c[i].x);
			r=small(r,c[i].y-y);
			r=small(r,Y-c[i].y);
			for(int j=0;j<n;j++){
				if(c[j].vis){
					r=small(r,dist(c[i],c[j])-c[j].r);
				}
			}
			if(r<0)r=0;
			c[i].vis=true;
			dfs(cnt+1,cur+Pi*r*r);
			c[i].vis=false;
		}
	}
}
int main(){
	scanf("%d%lf%lf%lf%lf",&n,&x,&y,&X,&Y);
	if(x>X)swap(&x,&X);
	if(y>Y)swap(&y,&Y);
	for(int i=0;i<n;i++){
		scanf("%lf%lf",&c[i].x,&c[i].y);
		c[i].vis=false;
	}
	dfs(0,0);
	printf("%d",(int)((X-x)*(Y-y))-(int)round(ans));
	return 0;
}
