#include<cstdio>
#include<algorithm>
using namespace std;
struct Student{
	char name[25];
	int sum,num;
    bool operator < (const Student& x)const{
		if(sum!=x.sum)return sum>x.sum;
		else return num<x.num;
	}
}s[105];
int main(){
	int n,ave,com,paper,sum=0;
	char isCadre,isWest;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s %d %d %c %c %d",s[i].name,&ave,&com,&isCadre,&isWest,&paper);
		s[i].num=i;s[i].sum=0;
		if(ave>80&&paper>=1)s[i].sum+=8000;
		if(ave>85&&com>80)s[i].sum+=4000;
		if(ave>90)s[i].sum+=2000;
		if(ave>85&&isWest=='Y')s[i].sum+=1000;
		if(com>80&&isCadre=='Y')s[i].sum+=850;
		sum+=s[i].sum;
	}
	sort(s,s+n);
	printf("%s\n%d\n%d",s[0].name,s[0].sum,sum);
	return 0;
}
