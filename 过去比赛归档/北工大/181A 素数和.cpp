#include<cstdio>
#include<cmath>
const int maxx=10000000;
const int NUM=670000;
bool vis[maxx+5];
int prime[NUM],cnt[NUM],k,s[NUM];
inline int read(){
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
    return x;
}
void build_prime(){
	int n=maxx;
	int m=sqrt(n+0.5);
	for(int i=2;i<=m;i++)
		if(!vis[i])
			for(int j=i*i;j<=n;j+=i)
				vis[j]=true;
	for(int i=2;i<=n;i++)if(!vis[i])prime[++k]=i;
//	printf("%d %d\n",k,prime[k-1]); 
}
int search(int x){
	int L=1,R=k,mid;
	while(L<=R){
		mid=(L+R)/2;
		if(prime[mid]==x)break;
		if(prime[mid]>x)R=mid-1;
		else L=mid+1;
	}
	if(prime[mid]<x)return mid+1;
	else return mid;
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,m,l,r,tmp;
	build_prime();
	scanf("%d",&n);
	while(n--){
		tmp=read();
		int mid=sqrt(tmp+0.5);
		for(int i=1;prime[i]<=mid&&tmp!=1;i++){
			if(tmp%prime[i]==0){
				cnt[i]++;
				while(tmp%prime[i]==0)tmp/=prime[i];
			}
		}
		if(tmp!=1)cnt[search(tmp)]++;
	}
	for(int i=1;i<=k;i++)cnt[i]+=cnt[i-1];//后缀数组，前n项和 
	scanf("%d",&m);	
	while(m--){
		l=read();r=read();
		int L=0,R=k;
		L=search(l);if(!(prime[L]<l&&l<=prime[L+1]))L--;
		R=search(r);if(!(prime[R]<=r&&r<prime[R+1]))R--;
		//printf("%d %d %d\n",L,R,cnt[R]-cnt[L]);
		printf("%d\n",cnt[R]-cnt[L]);
	}
	return 0;
}
