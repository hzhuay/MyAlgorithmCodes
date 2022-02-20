#include<cstdio>
#include<cstring>
int p[10005],n,cnt,ans[20005][2],j;
inline void change(int a,int b){int c=p[a];p[a]=p[b];p[b]=c;}
inline void swap(int l,int r){
	int len=(r-l+1)/2;
	for(int i=l;i<=(l+r)/2;i++)
		change(i,i+len);
	ans[j][0]=l;ans[j++][1]=r;
	cnt++;
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int T=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&p[i]);
		}
		cnt=0,j=0;
		for(int i=1;i<=n;i++){
			if(i==p[i])continue;
			int tmp=i;
			while(p[tmp]!=i)tmp++;
			int r=tmp*2-1-i;
			if(r<=n){
				swap(i,r);
			}else if((tmp-i)%2==0){
				swap(i+1,tmp);
				swap(i,tmp-1);
			}else{
				swap(i,tmp);
				swap(i,tmp-2);
			}
		}
		printf("%d\n",cnt);
		for(int i=0;i<j;i++){
			printf("%d %d\n",ans[i][0],ans[i][1]);
		}
	}	
	return 0;
}
