#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

#define eps 1e-8

struct point
{
    double x, y;
}p[1010];

double dist(point a, point b)
{
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double get_K(point a, point b)
{
    return (b.y - a.y) * 1.0 / (b.x - a.x);
}

point intersection(point u1, point u2, point v1, point v2)
{
    point ret = u1;
    double t = ((u1.x - v1.x)*(v1.y - v2.y) - (u1.y - v1.y)*(v1.x - v2.x))
        / ((u1.x - u2.x)*(v1.y - v2.y) - (u1.y - u2.y)*(v1.x - v2.x));
    ret.x += (u2.x - u1.x)*t;
    ret.y += (u2.y - u1.y)*t;
    return ret;
}

int main()
{
    int n;
    double h;
    while(cin>>n>>h&&(n||h)){
        p[0].x=0,p[0].y=h;
        for (int i = 1; i <= n; i++){
            cin>>p[i].x>>p[i].y;
        }
        double k=get_K(p[0],p[2]);
        double s=1.0*dist(p[1],p[2]);
        point mark = p[2];
        for (int i = 3; i <= n; i++)
        {
            
            if (get_K(p[0], p[i]) > k)
            {
                k = get_K(p[0], p[i]);
                point inter = intersection(p[0], mark, p[i], p[i - 1]);
                s += dist(p[i], inter);
                mark = p[i];
            }
        }
        cout <<fixed << setprecision(2) << s << endl;
    }
}
