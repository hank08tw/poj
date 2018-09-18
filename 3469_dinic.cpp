#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#define MAX_V 20005
//flow template with dinic弧優化
using namespace std;
struct edge{int to,cap,rev;};
vector<edge> G[MAX_V];
int level[MAX_V];
int iter[MAX_V];
bool used[MAX_V];
int n,m;
void add_edge(int from,int to,int cap){
        G[from].push_back((edge){to,cap,G[to].size()});
        G[to].push_back((edge){from,0,G[from].size()-1});
}

void bfs(int s){
	memset(level,-1,sizeof(level));
	queue<int> que;
	level[s]=0;
	que.push(s);
	while(!que.empty()){
		int v=que.front();que.pop();
		for(int i=0;i<G[v].size();i++){
			edge&e=G[v][i];
			if(e.cap>0&&level[e.to]<0){
				level[e.to]=level[v]+1;
				que.push(e.to);
			}
		}
	}
}
int dfs(int v,int t,int f){
        if(v==t)return f;
        used[v]=true;
        for(int &i=iter[v];i<G[v].size();i++){
                edge &e=G[v][i];
                if(e.cap>0&&level[v]<level[e.to]){
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
		bfs(s);
		if(level[t]<0)return flow;
                memset(iter,0,sizeof(iter));
                int f;
		while((f=dfs(s,t,2147483647))>0){flow+=f;}
        }
}
int tmp,a,b;
int main(){
	scanf("%d %d",&n,&m);
	int s=n,t=s+1;
	for(int i=0;i<n;i++){
		scanf("%d %d",&a,&b);
		add_edge(s,i,a);
		add_edge(i,t,b);
	}
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&a,&b,&tmp);
		add_edge(a-1,b-1,tmp);
		add_edge(b-1,a-1,tmp);
	}
	printf("%d\n",max_flow(s,t));
	memset(level,0,sizeof(level));
        memset(iter,0,sizeof(iter));
        memset(used,0,sizeof(used));
        for(int i=0;i<MAX_V;i++)G[i].clear();
}
