#include<cstdio>
#include<iostream>
using namespace std;
bool mark[10];
int a[10],res[10];
void permutation(int t){
	for(int i=0;i<4;i++){
	    if(!mark[i]){
	    	res[t]=a[i];
	    	mark[i]=1;
	    	permutation(t+1);
	    	for(i=0;i<9;i++)printf("%d",res[i]);puts("");
	    	mark[i]=0;
	    }	    	
	}
}
int main(){
	int i;
	for(i=0;i<9;i++)a[i]=i+1;
	permutation(0);	
	cout<<0x7f;
	return 0;
}
