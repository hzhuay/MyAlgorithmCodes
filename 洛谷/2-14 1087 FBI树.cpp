#include<cstdio>
char a[1100];
int s[1100],p[15]={1,2,4,8,16,32,64,128,256,512,1024,2048};;
inline int d(int l,int r){return s[r]-s[l-1];}
void build_tree(int x,int y,int l,int r){
	if(l==r)printf("%c","BI"[a[l]-'0']);//到叶子节点 
	else{
		build_tree(x+1,2*y-1,l,(l+r)/2);
		build_tree(x+1,2*y,(l+r)/2+1,r);
		if(d(l,r)==r-l+1)printf("I");//都是1
		else if(d(l,r)==0)printf("B");//都是0 
		else printf("F");//有0有1 
	}
}
int main(){
	int n;
	scanf("%d\n",&n);
	for(int i=1;i<=p[n];i++){
		scanf("%c",&a[i]);
		s[i]+=s[i-1]+a[i]-'0';
	}
	build_tree(1,1,1,p[n]);
	return 0;
}
