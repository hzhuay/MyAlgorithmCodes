#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct Pea{
    int r,c,n;
    Pea(int _r=0,int _c=0,int _n=0):r(_r),c(_c),n(_n){}
    bool operator < (const Pea& x)const{return n>x.n;}
}p[405];
int main(){
//	freopen("in.txt","r",stdin);
    int m,n,k,tmp,cnt=0,ans=0,cur=0;
    scanf("%d%d%d",&m,&n,&k);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++){
            scanf("%d",&tmp);
            if(tmp)p[++cnt]=Pea(i,j,tmp);	
        }
    sort(p+1,p+cnt+1);
    p[0]=Pea(0,p[1].c,0);
    for(int i=1;i<=cnt;i++){
    	cur+=abs(p[i].r-p[i-1].r)+abs(p[i].c-p[i-1].c)+1;
		if(cur+p[i].r<=k){
            ans+=p[i].n;
        }else{
            break;
        }
        
    }
    printf("%d",ans);
    return 0;
}
