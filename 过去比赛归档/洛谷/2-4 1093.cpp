#include<cstdio>
#include<algorithm>
using namespace std;
struct Student{
	int Ch,Ma,En,num,sum;
}s[305];
bool cmp(Student s1,Student s2){
	if(s1.sum!=s2.sum)return s1.sum>s2.sum;
	else{
		if(s1.Ch!=s2.Ch)return s1.Ch>s2.Ch;
		else return s1.num<s2.num;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		s[i].num=i+1;
		scanf("%d%d%d",&s[i].Ch,&s[i].Ma,&s[i].En);
		s[i].sum=s[i].Ch+s[i].Ma+s[i].En;
	}
	sort(s,s+n,cmp);
	for(int i=0;i<5;i++)printf("%d %d\n",s[i].num,s[i].sum);
	return 0;
}
