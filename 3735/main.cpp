#include <iostream>
#include <vector>
#define MAX 102
#define SWAP(a,b,tmp) (tmp=a),(a=b),(b=tmp)
using namespace std;
struct element{
    element(int r,int c,int v){
        row=r;
        col=c;
        val=v;
    }
    int row,col;
    long long val;
};
struct matrix{
    int m,n,nonzero;
    int first[MAX];
    int num[MAX];
    vector<element> ele;
};
matrix mult(matrix a,matrix b){
    matrix ans;
    ans.m=a.m;
    ans.n=b.n;
    memset(ans.num,0,sizeof(ans.num));
    ans.ele.clear();
    for(int i=1;i<a.ele.size ();i++){
        while(b.num[a.ele[i].row]>0){
            for(int j=b.first[i];j<b.first[i]+a.num[i];j++){

            }
        }
    }
}
int main() {
    int array[MAX][MAX];
    int n,m,k,change;
    while(scanf("%d %d %d",&n,&m,&k)){
        if(n==0&&m==0&&k==0)break;
        for(int i=1;i<=k;i++){
            memset(array,0,sizeof(array));
            for(int j=1;j<=n+1;j++){
                array[j][j]=1;
            }
            char ch;
            int t1,t2;
            scanf("%c",&ch);
            if(ch=='g'){
                scanf("%d",&t1);
                array[t1][n+1]=1;
            }
            else if(ch=='e'){
                scanf("%d",&t1);
                for(int j=1;j<=n+1;j++){
                    array[t1][j]=0;
                }
            }
            else if(ch=='s'){
                scanf("%d %d",&t1,&t2);
                for(int j=1;j<=n+1;j++){
                    SWAP(array[t1][j],array[t2][j],change);
                }
            }
            else{
                printf("uncorrect input\n");
            }
        }
        matrix mat;//這個矩陣要相乘m次 用三元組來快速運算稀疏矩陣
        mat.m=n+1;
        mat.n=n+1;
        mat.nonzero=0;
        memset(mat.first,1,sizeof(mat.first));
        memset(mat.num,0,sizeof(mat.num));
        mat.ele.push_back (element(0,0,0));
        for(int i=1;i<=n+1;i++){
            if(i>=2){
                mat.first[i]=mat.first[i-1]+mat.num[i];
            }
            for(int j=1;j<=n+1;j++){
                if(array[i][j]!=0){
                    mat.nonzero++;
                    mat.num[i]++;
                    mat.ele.push_back (element(i,j,array[i][j]));
                }
            }
        }
        matrix tmp=mat;
        matrix ans;
        for(int i=2;i<=k;i++){
            ans=mult(mat,tmp);
            tmp=ans;
        }

    }
    return 0;
}