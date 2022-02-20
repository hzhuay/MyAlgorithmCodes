#include<cstdio>
#include<cmath>
int a1[5700],b1[5700],a2[3000],b2[3000];
int main(){
	char c;
	int res1=0,res2=0;
	while(scanf("%c",&c),c!='E'){
		if(c=='L'){
			b1[res1]++;
			b2[res2]++;
		}else if(c=='W'){
			a1[res1]++;
			a2[res2]++;
		}
		
		if((a1[res1]>=11||b1[res1]>=11)&&abs(a1[res1]-b1[res1])>=2){
			res1++;
		}
		if((a2[res2]>=21||b2[res2]>=21)&&abs(a2[res2]-b2[res2])>=2){
			res2++;
		}
	}
	for(int i=0;i<=res1;i++)printf("%d:%d\n",a1[i],b1[i]);
	puts("");
	for(int i=0;i<=res2;i++)printf("%d:%d\n",a2[i],b2[i]);
	return 0;
}
