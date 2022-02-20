#include<stdio.h>
#include<stdlib.h>
#define N 1000001
typedef struct {
	int value;
	int index;
}QUE;
QUE min_que[N],max_que[N];
int n,k,num[N],front,rear;
int delete_rear_inc(int f,int r,int d){
	int mid;
	while(f<=r) {
		mid=(f+r)/2;
		if(min_que[mid].value==d)
			return mid;
		if(min_que[mid].value>d)
			r=mid-1;
		else
			f=mid+1;
	}
	return f;
}
int delete_rear_dec(int f,int r,int d)
{
	int mid;
	while(f<=r) {
		mid=(f+r)/2;
		if(max_que[mid].value==d)
			return mid;
		if(max_que[mid].value>d)
			f=mid+1;
		else
			r=mid-1;
	}
	return f;
}

int main(){
	int i;
//
	while(scanf("%d%d",&n,&k)!=EOF) {
		scanf("%d%d",&n,&k);
		for(i=1; i<=n; i++)
			scanf("%d",&num[i]);
//单调队列求最小——维持k区间的递增队列
		min_que[1].
		value=num[1];
		min_que[1].index=1;
		front=1;
		rear=1;
//1->k
		for(i=2; i<=k; i++) {
//删队尾，入队
			rear=delete_rear_inc(front,rear,num[i]);
			min_que[rear].value=num[i];
			min_que[rear].index=i;
		}

		printf("%d",min_que[1].value);
//队首即为第一个滑动窗口的最小值
//k+1->n
		for(i=k+1; i<=n; i++) {
//删队尾，入队,维持区间范围
			rear=delete_rear_inc(front,rear,num[i]);
			min_que[rear].value=num[i];
			min_que[rear].index=i;
//删队首，维持区间范围
			if(i-min_que[front].index>=k)
				front++;
//队首为第i-k+1个滑动窗口的最小值

			printf("%d",min_que[front].value);
		}
		printf("\n");
//单调队列求最大——维持k区间的递减队列
		max_que[1].value=num[1];
		max_que[1].index=1;
		front=1;
		rear=1;
//1->k
		for(i=2; i<=k; i++) {
//删队尾，入队
			rear=delete_rear_dec(front,rear,num[i]);
			max_que[rear].
			value=num[i];
			max_que[rear].index=i;
		}

		printf("%d",max_que[1].value);
//队首即为第一个滑动窗口的最大值
//k+1->n
		for(i=k+1; i<=n; i++) {
//删队尾，入队,维持区间范围
			rear=delete_rear_dec(front,rear,num[i]);
			max_que[rear].value=num[i];
			max_que[rear].index=i;
//删队首，维持区间范围
			if(i-max_que[front].index>=k)
				front++;
//队首为第i-k+1个滑动窗口的最大值
			printf("%d",max_que[front].value);
		}
		printf("\n");
	}
	return 0;
}
