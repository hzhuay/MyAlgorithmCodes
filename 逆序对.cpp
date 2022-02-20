//如果数列元素的大小是int范围的话，要加一步离散化 
/*我们可以先开一个大小为a的最大值的数组t，每当读入一个数时，我们可以用桶排序的思想，
将C[a[i]]加上1,然后我们统计C[1]~C[a[i]]的和ans，ans - 1（除掉这个数本身）就是在这个数前面有多少个数比它小。
我们只要用i-ans就可以得出前面有多少数比它大，也就是逆序对的数量。
*/
#include<cstdio>
#define lowbit(x) (-(x)&(x))//二进制按位与运算，返回不大于x的2的最大次方因子
const int M=500000+5;//数列元素的最大值 
int C[M];
int query(int x){//每个数前面有没有，有几个比自己大的数 
	int res=0;
	while(x>0){
		res+=C[x];
		x-=lowbit(x);
	}
	return res;
}
void update(int a){
	while(a<M){
		C[a]++;
		a+=lowbit(a);
	}	
}
int main(){
	int i,n,tmp,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&tmp);
		update(tmp);
		ans+=i-query(tmp);
	}
	printf("%d\n",ans);
	return 0;
}
