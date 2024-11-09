#include<cstdio>
#include<cstring>
using namespace std;
int n,C[15],vis[3][20],tot=0;
/*void search(int cur){
	if(cur==n)tot++;
	else for(int i=0;i<n;i++){
		int ok=1;
		C[cur]=i;
		for(int j=0;j<cur;j++)
			if(C[cur]==C[j]||cur-C[cur]==j-C[j]||cur+C[cur]==j+C[j]){
				ok=0;
				break;
				
			}
		if(ok)search(cur+1);
	}
}*/
void search(int cur){
	if(cur==n){
		tot++;
		for(int i=0;i<n;i++)printf("%d%c",C[i]+1," \n"[i==n-1]);
	}
	else for(int i=0;i<n;i++){
		if(!vis[0][i]&&!vis[1][cur+i]&&!vis[2][cur-i+n]){
			C[cur]=i;
			vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]=1;
			search(cur+1);
			vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]=0;
		}
	}
}
int main(){
	scanf("%d",&n);
	search(0);
	printf("%d",tot);
	return 0;
}
