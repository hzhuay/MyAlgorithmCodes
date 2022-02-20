#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
	freopen("test.in","r",stdin);
	int i,a,b,c,k[20],kase=1;
	bool mark=0;
	while(scanf("%d %d %d",&a,&b,&c)!=EOF){
		for(i=0;i<=20;i++){
			k[i]=0;
		}
		for(i=1;7*i+c<100;i++){
			k[i]=7*i+c;
		}
		cout<<"Case "<<kase<<": ";
		i=1;
		mark=0;
		while(k[i]){
			if(k[i]%5==b&&k[i]%3==a){
				printf("%d\n",k[i]);
				mark=1;
				break;
			}
			else {
				i++;
			}
		}
		if(!mark)puts("No answer");
		kase++;
	}
	return 0;
}
