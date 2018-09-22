#include <iostream>
#include <stdio.h>
#include <queue>
#define MAX_V 5005
#define INF 1000000000
#define SWAP(a,b,tmp) tmp=a,a=b,b=tmp
using namespace std;

struct edge{int to,cost;};
typedef pair<int,int> P;//first is shortest length, second is number of vertex
int tmp;
int V;
vector<edge> G[MAX_V];
int d[MAX_V];
int d2[MAX_V];
void dijstra(int s){
	priority_queue<P,vector<P>,greater<P> > que;//greater代表min heap
	fill(d,d+V,INF);
	fill(d2,d2+V,INF);
	d[s]=0;
	que.push(P(0,s));
	while(!que.empty()){
		P p=que.top();que.pop();
		int v=p.second;
		for(int i=0;i<G[v].size();i++){
			edge e=G[v][i];
			int newcost=p.first+e.cost;
			if(d[e.to]>newcost){
				SWAP(d[e.to],newcost,tmp);
				que.push(P(d[e.to],e.to));
			}
			if(d2[e.to]>newcost&&d[e.to]<newcost){
				/*d2[e.to]=newcost;*/SWAP(d2[e.to],newcost,tmp);
				que.push(P(d2[e.to],e.to));
			}
		}
	}
}
int main(){
	int r,a,b,w;
	scanf("%d %d",&V,&r);
	for(int i=0;i<r;i++){
		scanf("%d %d %d",&a,&b,&w);
		G[a-1].push_back((edge){b-1,w});
		G[b-1].push_back((edge){a-1,w});
	}
	dijstra(0);
	printf("%d\n",d2[V-1]);
}

/*
#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<set>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#include<deque>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<functional>
using namespace std;
 
#define N 5005
#define INF 100000000
typedef pair<int, int>P;
int n,r;
struct Edge{ int to, cost; };
vector<Edge>G[N];
int dist[N], dist2[N];
void addedge(int u, int v,int w)
{
	G[u].push_back(Edge{ v, w });
	G[v].push_back(Edge{ u, w });
}
void solve()
{
	priority_queue<P, vector<P>, greater<P> >q;
	fill(dist, dist + n, INF);//记录最短路
	fill(dist2, dist2 + n, INF);//记录次短路
	dist[0] = 0;
	q.push(P(0, 0));
	while (!q.empty())
	{
		P p = q.top(); q.pop();
		int v = p.second, d = p.first;
		for (int i = 0; i < G[v].size(); i++)
		{
			Edge&e = G[v][i];
			int d2 = d + e.cost;//v到相邻结点的距离
			if (dist[e.to]>d2)//更新e.to的最短距离
			{
				swap(dist[e.to], d2);
				q.push(P(dist[e.to], e.to));//最短距离入队列
			}
			if (dist2[e.to]>d2&&dist[e.to] < d2)//更新e.to的次短距离
			{
				dist2[e.to] = d2;
				q.push(P(dist2[e.to], e.to));//次短距离入队列
			}
		}
	}
	printf("%d\n", dist2[n - 1]);
}
 
int main()
{
	scanf("%d%d", &n, &r);
		int u, v, w;
		for (int i = 0; i < r; i++)
		{
			scanf("%d%d%d", &u, &v, &w);
			u--, v--;
			addedge(u, v, w);
		}
		solve();
	return 0;
}

*/
