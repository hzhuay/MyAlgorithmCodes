#include<bits/stdc++.h>
using namespace std;
const int maxn=10000+5;
char name[maxn][10];
int a[maxn];
int main(){
	int n,sum=0,ans=0;
	double ave;
	scanf("%d\n",&n);
	string line;
	for(int i=0;i<n;i++){
		getline(cin,line);
		stringstream ss(line);
		ss>>name[i]>>a[i];
		sum+=a[i];	
	}
	ave=sum*1.0/n/2;
	for(int i=0;i<n;i++)
		if(abs(ave-a[ans])>abs(ave-a[i]))ans=i;
	printf("%.0f %s",ave,name[ans]);
	return 0;
}
