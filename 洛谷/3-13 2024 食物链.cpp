#include<cstdio>
int f[300005];
inline int find(int k){return f[k]==k?k:f[k]=find(f[k]);}//查
inline void unity(int x,int y){f[find(f[x])]=find(f[y]);}//并 
inline int read(){
    int sum=0;
    char ch=getchar();
    while(ch>'9'||ch<'0') ch=getchar();
    while(ch>='0'&&ch<='9') sum=sum*10+ch-48,ch=getchar();
    return sum;
}
int main(){
	//freopen("eat.in","r",stdin);
	int n,k,p,x,y,ans=0;
	scanf("%d%d",&n,&k);
	//n=read(),k=read();
	for(int i=1;i<=3*n;i++)f[i]=i;//对于每种生物：设 x 为本身，x+n 为猎物，x+2*n 为天敌
	while(k--){
		scanf("%d%d%d",&p,&x,&y);
		//p=read(),x=read(),y=read();
		if(x>n||y>n)
			ans++;
		else
			if(p==1)//同类 
				if(find(x+n)==find(y)||find(x+2*n)==find(y))//如果 y是x的猎物或者天敌 
					ans++;
	            else
					unity(x,y),unity(x+n,y+n),unity(x+2*n,y+2*n);		
			else//吃掉 
				if(x==y)
					ans++;
				else if(find(x)==find(y)||find(x+2*n)==find(y))//如果 y是x的同类或者天敌 
					ans++;
				else	
					unity(x,y+2*n),unity(x+n,y),unity(x+2*n,y+n);		
	}
	printf("%d",ans);
	return 0;
}
