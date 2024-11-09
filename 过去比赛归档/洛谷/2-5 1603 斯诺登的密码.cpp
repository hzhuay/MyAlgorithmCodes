#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
char dic[30][20]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty","a","both","another","first","second","third"};//∂‘”¶
int di[30]={0,1,4,9,16,25,36,49,64,81,00,21,44,69,96,25,56,89,24,61,0,1,4,1,1,4,9};
int a[10];
char str[100];
int main(){
	int top;
	bool flag=false;
	for(int i=0;i<6;i++){
		scanf("%s",str);
		for(int j=0;j<26;j++){
			if(strcmp(str,dic[j])==0){
				a[top++]=di[j];
				break;
			}
		}
	}
	sort(a,a+top);
	for(int i=0;i<top;i++){
		if(flag)printf("%.2d",a[i]);
		else if(a[i]){
			printf("%d",a[i]);
			flag=true;
		}
	}
	if(!flag)printf("0");
	return 0;
}
