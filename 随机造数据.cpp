#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
	freopen("test.in","w",stdout);//freopen就放在main后面 
	int n,x,y;
	srand(time(NULL));//使用打这么一句 
	n=rand()%10+1;
	x=rand()%n+1;//+1啊，焕奇！！！！！！ 
	y=rand()%n+1;
	printf("1 %d\n%d %d",n,x,y);//一定要，但是这里换了个地方输出 
	return 0;
}

