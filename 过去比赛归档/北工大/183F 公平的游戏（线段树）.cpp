#include<cstdio>
#include<algorithm>
#define M 100005
using namespace std;
struct node{
	int L,R,sum;
}tree[M<<2];
int A[M],B[M],op[M],k[M];
void up(int p){
	tree[p].sum=tree[p<<1].sum+tree[p<<1|1].sum;
}
void build(int L,int R,int p){
	tree[p].L=L;
	tree[p].R=R;
	if(L==R){
		tree[p].sum=0;
		return;
	}
	int mid=(L+R)>>1;
	build(L,mid,p<<1);
	build(mid+1,R,p<<1|1);
	up(p);
}
int query(int x,int p){
	if(tree[p].L==tree[p].R)return tree[p].L;
	if(x<=tree[p<<1|1].sum)query(x,p<<1|1);
	else query(x-tree[p<<1|1].sum,p<<1);
}
void update(int a,int b,int p){
	if(tree[p].L==tree[p].R){
		tree[p].sum=b;
		return;
	}
	int mid=(tree[p].L+tree[p].R)>>1;
	if(a<=mid)update(a,b,p<<1);
	else update(a,b,p<<1|1);
	up(p);
}
int discrete(int n){
	int j=0;
	for(int i=0;i<n;i++)
		if(op[i]!=2){
			A[j]=B[j]=k[i];
			j++;
		}	
	sort(B,B+j);
	int m=unique(B,B+j)-B;
	for(int i=0;i<j;i++)
		A[i]=lower_bound(B,B+m,A[i])-B+1;
//B[A[i]-1]ÕÒÔ­À´Öµ
	
	/*for(int i=0;i<j;i++)printf("%d ",A[i]);
	puts("");
	for(int i=0;i<m;i++)printf("%d ",B[i]);
	printf("\n%d %d\n",m,j);*/
	return m;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&op[i],&k[i]);
	}
	build(1,discrete(n),1);
	int j=0;
	for(int i=0;i<n;i++){
		if(op[i]==0){
			update(A[j++],1,1);
		}else if(op[i]==1){
			update(A[j++],0,1);
		}else if(op[i]==2){
			printf("%d\n",B[query(k[i],1)-1]);
		}
	}
	return 0;
}
