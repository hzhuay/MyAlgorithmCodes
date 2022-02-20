#include<cstdio>
#define M 100005
using namespace std;
struct node{
	int L,R,x;
}tree[M<<2];
int A[M];
void up(int p){
	tree[p].x=tree[p<<1].x+tree[p<<1|1].x;
}
void build(int L,int R,int p){
	tree[p].L=L;
	tree[p].R=R;
	if(L==R){
		tree[p].x=A[L];
		return;
	}
	int mid=(L+R)>>1;
	build(L,mid,p<<1);
	build(mid+1,R,p<<1|1);
	up(p);
}
int query(int L,int R,int p){
	if(tree[p].L==L&&tree[p].R==R)
		return tree[p].x;
	int mid=(tree[p].L+tree[p].R)>>1;
	if(R<=mid)return query(L,R,p<<1);
	else if(L>mid)return query(L,R,p<<1|1);
	else{
		return query(L,mid,p<<1)+query(mid+1,R,p<<1|1);
	}
}
int main(){
	int i,n,q;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&A[i]);
	build(1,n,1);
	scanf("%d",&q);
	while(q--){
		int L,R;
		scanf("%d %d",&L,&R);
		printf("%d\n",query(L,R,1));
	}
	return 0;
}
