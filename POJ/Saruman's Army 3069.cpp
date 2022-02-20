#include<cstdio>
#include<algorithm>
#include<cstring>
#define M 1005
using namespace std; 
int a[M],ans,len,n,r;
void f(int aim){
	if(aim==len-1){ans++;return;}
	int i,j;
	for(i=aim+1;i<len;i++){
		if(a[i]-r>a[aim]){
			printf("%d ",i-1);
			for(j=i;j<len;j++){
				if(a[j]>a[i-1]+r){
					ans++;
					printf("%d\n",j);
					return f(j);	
				}
			}
		}
	}	
}
int main(){
	int i;
	while(scanf("%d%d",&r,&n),r!=-1){
		ans=0;
		memset(a,0,sizeof(a));
		for(i=0;i<n;i++)scanf("%d",&a[i]);
		sort(a,a+n);
		len=unique(a,a+n)-a;
		f(0);
		printf("%d\n",ans);
	}
	return 0;
}	
