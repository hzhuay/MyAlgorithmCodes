#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char che[100],name[4]={'C','H','O','N'};
int N[80];
bool flag[80];
int main(){
	int len,j,kase,per=0;
	double molar[]={12.01,1.008,16.00,14.01},ans=0;
	cin>>kase;
	for(int t=0;t<kase;t++){
		ans=0;
		scanf("%s",che);
		len=strlen(che);
		for(int i=0;i<len;i++)
			if(che[i]>='C'&&che[i]<='O'){
				if(che[i+1]>'0'&&che[i+1]<'9'){
					j=i+1;
					while(che[j]>'0'&&che[j]<'9')
						per=per*10+che[j++]-48;
					N[che[i]]+=per;
					per=0;
				}
				else N[che[i]]++;
			}
		for(int turn=0;turn<4;turn++)
			ans+=N[name[turn]]*molar[turn];
		memset(N,0,sizeof(N));
	printf("%.3f\n",ans);
	}
	return 0;
}
