#include<cstdio>
#include<cstring>
int p[505],ans[505];
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int kase;
	scanf("%d",&kase);
	while(kase--){
		int m,k,L=0,x=0;
		long long R=0;
		scanf("%d%d",&m,&k);
		k--;
		for(int i=0;i<m;i++){
			scanf("%d",&p[i]);
			R+=p[i];
			if(L<p[i])L=p[i];
		}
		int mid=L,cnt;
		long long tmp=0;
		while(L<=R){//L不行，R可以 
			cnt=k;tmp=0;
			for(int i=0;i<m;i++){
				if(tmp+p[i]<=mid){
					tmp+=p[i];
				}else{
					tmp=p[i];
					cnt--;
				}
			}
			if(cnt<0){//cnt<0,mid太小，k不够.不行 
				L=mid+1;
			}else{//cnt>=0,mid太大，k多余了，可以 
				R=mid-1;
			}
			mid=(L+R)/2;
		}
		cnt=k;tmp=0;
		for(x=m-1;x>=0;x--){
			if(tmp+p[x]<=L){
				tmp+=p[x];
			}else{
				tmp=p[x];
				cnt--;
				ans[x]=1;
			}
			if(x==cnt)break;
		}
		while(cnt)ans[--cnt]=1;
		for(int i=0;i<m;i++){
			printf("%d%c",p[i]," \n"[i==m-1]);
			if(ans[i])printf("/ ");
		}
		//printf("%d %d %d\n",L,mid,R);
		memset(ans,0,sizeof(ans));
		memset(p,0,sizeof(p));
	}
	return 0;
} 
