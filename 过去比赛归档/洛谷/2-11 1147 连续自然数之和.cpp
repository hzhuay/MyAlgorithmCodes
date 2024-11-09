#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=sqrt(n*2);i>1;i--)//i*m=2*n
		if(2*n%i==0&&(i+2*n/i)%2==1){//m为整数&&i和m一奇一偶 
			int m=2*n/i;
			printf("%d %d\n",(m-i+1)/2,(i+m-1)/2);
		}
	return 0;
}
