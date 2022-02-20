#include<cstdio>
#include<iostream>
using namespace std;
int cube(int x){
	return x*x*x;
}
int main(){
	int a,b,c;
	for(a=1;a<=9;a++){
		for(b=0;b<=9;b++){
			for(c=0;c<=9;c++){
				if(a*100+b*10+c==cube(a)+cube(b)+cube(c))cout<<a*100+b*10+c<<endl;
			}
		}
	}
	return 0;
} 
