#include <iostream>
#include <queue>
#define MAX_V 1000
#define INF 1000000000
using namespace std;

struct edge{int to,cost;};
typedef pair<int,int> P;//first is shortest length, second is number of vertex

int V;
vector<edge> G[MAX_V];
int d[MAX_V];

void dijstra(int s){
	priority_queue<P,vector<P>,greater<P> > que;//greater代表min heap
	fill(d,d+V,INF);
	d[s]=0;
	que.push(P(0,s));
	
	while(!que.empty()){
		P p=que.top();que.pop();
		int v=p.second;
		//if(d[v]<p.first)continue;
		for(int i=0;i<G[v].size();i++){
			edge e=G[v][i];
			if(d[e.to]>d[v]+e.cost){
				d[e.to]=d[v]+e.cost;
				que.push(P(d[e.to],e.to));
			}
		}
	}
}
int main(){

}
