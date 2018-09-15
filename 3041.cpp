#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>
#define MAX_V 1005
//flow template
using namespace std;
struct edge{int to,cap,rev;};
vector<edge> G[MAX_V];
bool used[MAX_V];
int n,k;
void add_edge(int from,int to,int cap){
	G[from].push_back((edge){to,cap,G[to].size()});
	G[to].push_back((edge){from,0,G[from].size()-1});
}
int dfs(int v,int t,int f){
	if(v==t)return f;
	used[v]=true;
	for(int i=0;i<G[v].size();i++){
		edge &e=G[v][i];
		if(!used[e.to]&&e.cap>0){
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0){
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
int max_flow(int s,int t){
	int flow=0;
	while(true){
		memset(used,0,sizeof(used));
		int f=dfs(s,t,100000);
		if(f==0)return flow;
		flow+=f;
	}
}
int tmpx,tmpy;
int main(){
	scanf("%d %d",&n,&k);
	int s=2*n,t=s+1;
	for(int i=0;i<n;i++){
		add_edge(s,i,1);
		add_edge(i+n,t,1);
	}
	for(int i=0;i<k;i++){
		scanf("%d %d",&tmpx,&tmpy);
		add_edge(tmpy-1,tmpx-1+n,1);
	}
	printf("%d\n",max_flow(s,t));
	return 0;
}
