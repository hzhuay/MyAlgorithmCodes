#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int dvd,div,i=0;
	cin>>dvd>>div;
	printf("%d",dvd/div);
	if(dvd%div!=0)printf(".");
	dvd%=div;
	while(dvd&&i<=100){
		dvd*=10;
		if(dvd>div)printf("%d",dvd/div);
		dvd%=div;
		i++;
	}
	return 0;
}
