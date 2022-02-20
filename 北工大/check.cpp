# include<iostream>
# include<queue>
# define MAX 5842
using namespace std;

__int64 humble_number[MAX+1];

struct cmp1{
    bool operator()(__int64 &a,__int64 &b)
    {
        return a>b;//?????
    }
};

int main()
{
    int i=1,n;
    humble_number[0]=0;
    priority_queue<__int64,vector<__int64>,cmp1> q;
    while(i<=MAX)
    {
        q.push(1);
        while(!q.empty())
        {
            if(i>MAX)
                break;
            __int64 j=q.top();
            q.pop();
            if(j!=humble_number[i-1])
            {
                humble_number[i++]=j;
                q.push(j*2);
                q.push(j*3);
                q.push(j*5);
                q.push(j*7);
            }
        }
    }
    /*
	while(cin>>n)
    {
        if(n==0)
            break;
		else
        {
            if(n%10==1&&n%100!=11)
                printf("The %dst humble number is %d.\n",n,humble_number[n]);
            else if(n%10==2&&n%100!=12)
                printf("The %dnd humble number is %d.\n",n,humble_number[n]);
            else if(n%10==3&&n%100!=13)
                printf("The %drd humble number is %d.\n",n,humble_number[n]);
            else
                printf("The %dth humble number is %d.\n",n,humble_number[n]);
        }
    }
    */
    
    for(int i=1;i<=5842;i++)
    	printf("%d\n",humble_number[i]);
    return 0;
}

