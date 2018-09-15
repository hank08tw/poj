#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>
#define MAX_V 20005
//flow template,too slow
using namespace std;
struct edge{int to,cap,rev;};
vector<edge> G[MAX_V];
bool used[MAX_V];
int n,m;
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
}
