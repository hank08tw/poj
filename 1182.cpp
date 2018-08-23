#include <iostream>
#include <stdio.h>
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
int main(){
        int n,k,t,x,y;
	int ans=0;
        scanf("%d%d",&n,&k);
        init(3*n);
        for(int i=1;i<=k;i++){
                scanf("%d%d%d",&t,&x,&y);
                if(x<=0||y<=0||x>n||y>n){ans++;continue;}
                if(t==1){
                        if(same(x,y+n)||same(x,y+2*n)||same(x,y+n)||same(x+n,y)||same(x,y+2*n)||same(x+2*n,y)||same(x+n,y+2*n)||same(x+2*n,y+n)){ans++;}
                        else{
                                unite(x,y);
                                unite(x+n,y+n);
                                unite(x+2*n,y+n*2);
                        }
                }else{
                        if(same(x,y)||same(x,y+2*n)||same(x,y)||same(x+n,y+n)||same(x+2*n,y+2*n)||same(x,y+2*n)||same(x+n,y)||same(x+2*n,y+n)){ans++;}
                        else{
                                unite(x,y+n);
                                unite(x+n,y+2*n);
                                unite(x+n*2,y);
                        }
                }
        }
        printf("%d\n",ans);
}
