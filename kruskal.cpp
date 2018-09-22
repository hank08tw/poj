#include <iostream>
#include <stdio.h>
#define MAX_E 100000
using namespace std;
struct edge{int u,v,cost;};
#include <cstdio>
#define MAX 155000
using namespace std;
int par[MAX];
int rk[MAX];

void init(int n){
        for(int i=1;i<=n;i++){
                par[i]=i;
                rk[i]=0;
        }
}
int find(int x){
        if(par[x]==x){//如果是根回傳自己
                return x;
        }else{//如果不是根 把她的parent改成根
                return par[x]=find(par[x]);
        }
}
void unite(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return;
        if(rk[x]<rk[y])par[x]=y;
        else{
                par[y]=x;
                if(rk[x]==rk[y])rk[x]++;
        }
}
bool same(int x,int y){return find(x)==find(y);}

bool comp(const edge& e1, const edge& e2){
	return e1.cost < e2.cost;
}

edge es[MAX_E];
int V,E;

int kruskal(){
	sort(es,es+E,comp);
	init(V);
	int res=0;
	for(int i=0;i<E;i++){
		edge e=es[i];
		if(!same(e.u,e.v)){
			unite(e.u,e.v);
			res+=e.cost;
		}
	}
	return res;
}
int main(){
	
}
