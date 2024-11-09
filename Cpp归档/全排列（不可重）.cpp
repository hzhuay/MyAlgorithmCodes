#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
bool mark[7];
char str[7],res[7];
void f(int t,int x){
	 if (t==x){
	 	cout<<res<<endl; 
	 	return;
	 }
	 for(int i=0;i<x;i++){
	    if(!mark[i]){
	    	res[t]=str[i];
	    	mark[i]=1;
	    	f(t+1,x);
	    	mark[i]=0;
	    }	    	
	}
}
int main(){
	int n;
	cin>>str;
	n=strlen(str);
	f(0,n);	
	return 0;
}
