#include<cstdio>
#include<algorithm>
using namespace std;
char str[710];
int main(){
//	freopen("in.txt","r",stdin);
	int n,ans=0,j;
	scanf("%d\n%s",&n,str);
	for(int i=0;i<n;i++)str[i+n]=str[i];
	for(int i=0;i<n;i++){
		bool flag=true;
		char cur=str[i];
		for(j=i+1;j<i+n;j++){
			if(cur=='w'){
				if(str[j]!='w')cur=str[j];
			}else{
				if(cur!=str[j]&&str[j]!='w'){
					if(flag){
						flag=false;
						cur=str[j];
					}else{
						break;
					}
				}
			}
		}
		ans=max(ans,j-i);
	}
	printf("%d",ans);
	return 0;
}
