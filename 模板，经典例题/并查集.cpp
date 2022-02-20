//并查集 
#include<bits/stdc++.h>
using namespace std;
int f[10010];
int find(int k){
    if(f[k]==k)return k;
    return f[k]=find(f[k]);
}
int main(){
	int n,m,p1,p2,p3;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)f[i]=i;//初始化i的老大为自己 
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&p1,&p2,&p3);
        if(p1==1)
            f[find(p2)]=find(p3);//p3打赢了p2
        else
            if(find(p2)==find(p3))//是否是一伙的 
                printf("Y\n");
            else
                printf("N\n");
    }
    return 0;
}
