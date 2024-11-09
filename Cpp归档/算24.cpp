#include<iostream>
#include<cmath>
#define EPS 1e-6
double a[5];
using namespace std;
bool iszero (double x){
	return fabs(x)<=EPS;//fabs()是取double型的绝对值 
}
bool count(double a[],int n){
	if(n==1){
		if(iszero(a[0]-24))return true; 
		else return false;
	}
	double b[5];
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int m=0;
			for(int k=0;k<n;k++)
				if(k!=i&&k!=j){
					b[m]=a[k];
					m++;
				}
			b[m]=a[i]+a[j];
			if(count(b,m+1))return true;
			b[m]=a[i]-a[j];
			if(count(b,m+1))return true;
			b[m]=a[j]-a[i];
			if(count(b,m+1))return true;
			b[m]=a[i]*a[j];
			if(count(b,m+1))return true;
			if(!iszero(a[j])){
				b[m]=a[i]/a[j];
				if(count(b,m+1))return true;
			}
			if(!iszero(a[i])){
				b[m]=a[j]/a[i];
				if(count(b,m+1))return true;
			}
		}
	}
	return false;
}
int main(){
	while(scanf("%lf%lf%lf%lf",&a[0],&a[1],&a[2],&a[3])!=EOF){
		if(iszero(a[0]))break;
		if(count(a,4))cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}			
	return 0;
}
