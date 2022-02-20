#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue> 
#include<climits>
using namespace std;
const int maxn=10005;
int inq[maxn],cnt[maxn];
struct Edge{
	int from,to,dist;
	Edge(int u,int v,int d):from(u),to(v),dist(d){}
};
struct HeapNode{
	int d,u;
	bool operator < (const HeapNode& rhs) const{
		return d>rhs.d;
	}
};
struct Dijkstra{//不带负权 
	int n,m;
	vector<Edge>edges;
	vector<int>G[maxn];
	bool done[maxn];
	int d[maxn];
	int p[maxn];
	void init(int n){
		this->n=n;
		for(int i=0;i<=n;i++)G[i].clear();
		edges.clear();
	}
	void AddEdge(int from,int to,int dist){
		edges.push_back(Edge(from,to,dist));
		m=edges.size();
		G[from].push_back(m-1);
	}
	void dijkstra(int s){
		priority_queue<HeapNode>Q;
		for(int i=1;i<=n;i++)d[i]=INT_MAX;
		d[s]=0;
		memset(done,0,sizeof(done));
		Q.push((HeapNode){0,s});
		while(!Q.empty()){
			HeapNode x=Q.top();Q.pop();
			int u=x.u;
			if(done[u])continue;
			done[u]=true;
			for(int i=0;i<(int)G[u].size();i++){
				Edge& e=edges[G[u][i]];
				if(d[e.to]>d[u]+e.dist){
					d[e.to]=d[u]+e.dist;
					p[e.to]=G[u][i];
					Q.push((HeapNode){d[e.to],e.to});
				}
			}
		}
	}
	
	bool bellman_ford(int s){//带负权 
		queue<int>Q;
		memset(inq,0,sizeof(inq));
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++)d[i]=INT_MAX;
		d[s]=0;
		inq[s]=true;
		Q.push(s);
		while(!Q.empty()){
			int u=Q.front();Q.pop();
			inq[u]=false;
			for(int i=0;i<(int)G[u].size();i++){
				Edge& e=edges[G[u][i]];
				if(d[u]<INT_MAX&&d[e.to]>d[u]+e.dist){
					d[e.to]=d[u]+e.dist;
					p[e.to]=G[u][i];
					if(!inq[e.to]){
						Q.push(e.to);
						inq[e.to]=true;
						if(++cnt[e.to]>n)return false;
					}
				}
			}
		}
		return true;
	}	
};
int main(){
//	freopen("in.txt","r",stdin);
	Dijkstra D;
	int u,v,w,n,m,s;
	scanf("%d%d%d",&n,&m,&s);
	D.init(n);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&w);
		D.AddEdge(u,v,w);
		//D.AddEdge(v,u,w);
	}
	//D.dijkstra(s);
	D.bellman_ford(s);
	for(int i=1;i<=n;i++)
		printf("%d ",D.d[i]);
	return 0;
} 
