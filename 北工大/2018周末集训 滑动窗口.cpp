#include<cstdio>
#include<set>
using namespace std;
const int maxn=1000000+5;
multiset<int>s;
int num[maxn],ansmax[maxn],ansmin[maxn];
int main(){
	//freopen("out.txt","w",frontdout);
	int n,k,j=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
		s.insert(num[i]);
		if(i>=k){
			multiset<int>::iterator iter=s.find(num[i-k]);
			if (iter!=s.end())s.erase(iter);
			ansmin[j]=*s.begin();
			iter=s.end();
			iter--;
			ansmax[j]=*iter;
			/*for(iter=s.begin();iter!=s.end();iter++)
				printf("%d%c",*iter," \n"[iter==s.end()]);
			puts("");*/
			j++;
		}	
	}
	j--;
	for(int i=0;i<=j;i++)
		printf("%d%c",ansmin[i]," \n"[i==j]);
	for(int i=0;i<=j;i++)
		printf("%d%c",ansmax[i]," \n"[i==j]);
	return 0;
}
