//不要害怕变量多，不要过分追求变量复用多用，变量多比写不出好 
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=100000+5;
int to[maxn],ori[maxn],from_ori[maxn],in[maxn],size[maxn];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&to[i]);
	for(int i=1;i<=n;i++){
		for(int j=i,cnt=0;;j=to[j],cnt++){
			if(!ori[j]){//第一次访问 
				ori[j]=i;
				from_ori[j]=cnt;
			}else if(ori[j]==i){//回到起点 
				size[i]=cnt-from_ori[j];
				in[i]=from_ori[j];
				printf("%d\n",cnt); 
				break;
			}else{//进入起点不同但走过的老路(环)
				size[i]=size[ori[j]];
				in[i]=cnt+max(in[ori[j]]-from_ori[j],0);//该节点在不在环中 
				printf("%d\n",in[i]+size[i]);
				break;
			}
		}
	}
	return 0;
} 
