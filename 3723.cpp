#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#define MAX_V 20005
#define INF 1000000000
#define MAX_E 50005
using namespace std;
struct edge{int u,v,cost;};
#include <cstdio>
#define MAX 155000
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

int n,m,r,t,x,y,d;

int main(){
        scanf("%d",&t);
        while(t--){
		
                scanf("%d %d %d",&n,&m,&r);
                V=n+m;
                E=r;
                for(int i=0;i<E;i++){
                        scanf("%d %d %d",&x,&y,&d);
                        es[i]=(edge){x,y+n,-d};
                }
                printf("%d\n",10000*V+kruskal());
		
        }
        return 0;
}/*
#include <cstdio>
#include <algorithm>
#define MAX 10000
using namespace std;

int par[MAX*2];
int height[MAX*2];
int N,M,R;


void init_union_find(int v)
{
    for(int i=0;i<v;i++)
    {
        par[i]=i;
    }
    fill(height,height+v,0);
}
int  find_root(int x)
{
    if(par[x]==x)
    {
        return x;
    }
    return find_root(par[x]);
}
void unite(int x,int y)
{
    x = find_root(x);
    y = find_root(y);
    if(x==y)
    {
        return;
    }

    if(height[x]>height[y])
    {
        par[y]=x;
    }
    else
    {
        par[x]=y;
        if(height[x]==height[y])
        {
            height[y]++;
        }
    }
}
bool same(int x,int y)
{
    return find_root(x)==find_root(y);
}


struct edge {
    int u,v,cost;
};

bool comp(const edge& e1,const edge& e2)
{
    return e1.cost<e2.cost;
}
edge es[MAX*5];



int kruskal()
{
    sort(es,es+R,comp);
    init_union_find(N+M);
    int res = 0;
    for(int i=0;i<R;i++)
    {
        edge e = es[i];
        //printf("edge e :%d %d %d",es[i].u,es[i].v,es[i].cost);
        if(!same(e.u,e.v))
        {
            unite(e.u,e.v);
            res += e.cost;
        }
    }
    return res;
}

int main()
{
    int loop;
    scanf("%d",&loop);
    int u,v,cost;
    for(int i=0;i<loop;i++)
    {
        scanf("%d%d%d",&N,&M,&R);
        for(int j=0;j<R;j++)
        {
            scanf("%d%d%d",&u,&v,&cost);
            es[j].cost = -cost;
            es[j].u = u;
            //这里为什么要加上女生的人数而不是男生的人数？我认为应该加男生的人数
            es[j].v = v+N;
        }
        printf("%d\n",(N+M)*MAX+kruskal());
    }
    return 0;
}
*/
