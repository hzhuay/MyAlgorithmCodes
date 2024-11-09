#include<iostream>
#include<cmath>
#include<algorithm>
#define EPS 1e-6
double a[5];
using namespace std;
bool iszero (double x){
	return fabs(x)<=EPS;//fabs()是取double型的绝对值 
}
bool count(int i){
	if(i==4){
		if(iszero(a[0]-24))return true;
		else return false;
	}
		a[0]+=a[i];
		if(count(++i))return true;
		a[0]-=a[i];
		if(count(++i))return true;
		a[0]=a[i]-a[0];
		if(count(++i))return true;
		a[0]*=a[i];
		if(count(++i))return true;
		if(!iszero(a[0])){
			a[0]=a[i]/a[0];
			if(count(++i))return true;
		}
		if(!iszero(a[i])){
			a[0]/=a[i];
			if(count(++i))return true;
		}
	return false;
}
int main(){
	while(cin>>a[0]>>a[1]>>a[2]>>a[3]){
		if(a[0]==0&&a[1]==0&&a[2]==0&&a[3]==0)return 0;
		do{
			cout<<a[0]<<a[1]<<a[2]<<a[3]<<endl;
			if(count(1))cout<<"YES"<<endl;
			else cout<<"NO"<<endl;	
		}while(next_permutation(a+1,a+5));	
	}			
	return 0;
}
