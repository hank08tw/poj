#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<vector>
#include<queue>
#include<string>
#include<sstream>
#define eps 1e-9
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FOR(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
typedef long long LL;
int i,j,k,n,m,x,y,T,ans,big,cas,match[505],g[505][505],r,c;
bool flag,vis[505];

bool hungary(int u)//从u开始寻找增广路
{
    for (int i=1;i<=n;i++)
    {
        if (g[u][i]&&!vis[i])//G数组存储邻接矩阵，match[i]表示当前结点i匹配的结点
        {
            vis[i]=1;
            if (match[i]==0||hungary(match[i]))
                return match[i]=u;
        }
    }
    return 0;
}

int main()
{
    scanf("%d%d",&n,&k);
    for (i=1;i<=k;i++)
    {
        scanf("%d%d",&r,&c);
        g[r][c]=1;
    }
    ans=0;

        /*匈牙利算法过程 - 寻找增广路*/
    for (i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        if (hungary(i)) ans++;
    }
    /*寻找结束*/

    printf("%d\n",ans);
    return 0;
}
