//bellman-ford min-cost-flow算法可以有負邊 F次bellman-ford 時間:o(FVE)
#include <iostream>
#include <stdio.h>
#include <vector>
#define MAX_V 1005
#define INF 2147483647
using namespace std;
struct edge{int to,cap,cost,rev;};
int V;
vector<edge> G[MAX_V];
int dist[MAX_V];
int prevv[MAX_V],preve[MAX_V];

void add_edge(int from,int to,int cap,int cost){
	G[from].push_back((edge){to,cap,cost,G[to].size()});
	G[to].push_back((edge){from,0,-cost,G[from].size()-1});
}

int min_cost_flow(int s,int t,int f){
	int res=0;
	while(f>0){
		fill(dist,dist+V,INF);
		dist[s]=0;
		bool update=true;
		while(update){
			update=false;
			for(int v=0;v<V;v++){
				if(dist[v]==INF)continue;
				for(int i=0;i<G[v].size();i++){
					edge &e=G[v][i];
					if(e.cap>0&&dist[e.to]>dist[v]+e.cost){
						dist[e.to]=dist[v]+e.cost;
						prevv[e.to]=v;
						preve[e.to]=i;
						update=true;
					}
				}
			}
		}
		if(dist[t]==INF)return -1;
		

		int d=f;
		for(int v=t;v!=s;v=prevv[v]){
			d=min(d,G[prevv[v]][preve[v]].cap);
		}
		f-=d;
		res+=d*dist[t];
		for(int v=t;v!=s;v=prevv[v]){
			edge &e =G[prevv[v]][preve[v]];
			e.cap-=d;
			G[v][e.rev].cap+=d;
		}
	}
	return res;
}
int n,m,a,b,len;
int main(){
	scanf("%d %d",&n,&m);
	int s=0,t=n-1;
	V=n;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&a,&b,&len);
		add_edge(a-1,b-1,1,len);
		add_edge(b-1,a-1,1,len);
	}
	printf("%d\n",min_cost_flow(s,t,2));
	return 0;
}
