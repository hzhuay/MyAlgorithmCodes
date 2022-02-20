#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include <iomanip>
using namespace std;
const int maxn=1010;
const double EXP=1e-8;
struct Point{
    double x,y;
}p[maxn];
inline double lineLength(Point p1,Point p2){return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));}
inline double getK(Point p1,Point p2){return (p1.y-p2.y)*1.0/(p1.x-p2.x);}
Point intersection(Point u1, Point u2, Point v1, Point v2){
    Point node=u1;
    double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))/((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
    node.x+=(u2.x-u1.x)*t;
    node.y+=(u2.y-u1.y)*t;
    return node;
}

int main(){
	//freopen("text.in","r",stdin); 
	int n,h;
	while(scanf("%d%d",&n,&h)&&(n||h)){
		p[0].x=0;p[0].y=h;	
		for(int i=1;i<=n;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		double k=getK(p[2],p[0]);
		double ans=1.0*lineLength(p[2],p[1]);
		int highpoint=2;
		for(int i=3;i<=n;i++){
			double tmpk=getK(p[i],p[0]);
			if(tmpk-k>EXP){
				Point cross=intersection(p[0],p[highpoint],p[i],p[i-1]);
				ans+=lineLength(p[i],cross);
				k=tmpk;
				highpoint=i;
			}
		}
		printf("%.2f\n",ans);
		memset(p,0,sizeof(p));
	}
	return 0;
}
