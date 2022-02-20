#include<iostream>  
#include<cstdio>  
#include<cstring>  
using namespace std;  
const int maxn=30;  
  
char PR[maxn],IN[maxn];          
int Left['Z'],Right['Z'],pr[maxn],in[maxn]; 
int n,root; 
    
int build(int L1,int R1,int L2,int R2){//先序：1，中序：2 
    if(L1>R1)return 0;//空树 
    int rt=pr[L1]; 
    //printf("%d %d %d %d | %d %d\n",L1,R1,L2,R2,rt,pr[L1]);
    int p=0;  
    while(in[p]!=rt)p++;
    int cnt=p-L2;//有cnt个左节点 
    //printf("%d %d %d:\n%d %d %d %d\n%d %d %d %d\n",rt,p,cnt,L1+1,L1+cnt,L2,p-1,L1+cnt+1,R1,p+1,R2);
	Left[rt]=build(L1+1,L1+cnt,L2,p-1);
    Right[rt]=build(L1+cnt+1,R1,p+1,R2);
    return rt;
}
   
void poOrder(int rt){  
    if(Left[rt]!=0)   
        poOrder(Left[rt]);  
    if(Right[rt]!=0)   
        poOrder(Right[rt]);  
    printf("%c",rt+'A'-1);
} 
  
int main(){  
    //freopen("in.txt","r",stdin);
	while(scanf("%s",PR)!=EOF){      
        scanf("%s",IN);
        //printf("%s %s\n",PR,IN);
        int n=strlen(PR);
        for(int i=1;i<=n;i++){
        	pr[i]=PR[i-1]-'A'+1;
        	in[i]=IN[i-1]-'A'+1;
		}
		root=build(1,n,1,n);           
		poOrder(root);           
        puts("");
		memset(Left,0,sizeof(Left));   
        memset(Right,0,sizeof(Right)); 
		memset(Right,0,sizeof(PR)); 
		memset(Right,0,sizeof(IN)); 
		memset(Right,0,sizeof(pr)); 
		memset(Right,0,sizeof(in));  
    }  
    return 0;  
}
