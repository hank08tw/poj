//https://www.nowcoder.com/question/next?pid=9763997&qid=152612&tid=17867370 牛牛的背包問題 折半枚舉o(n*2^n)
#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <cstdio>
#include <algorithm>
using namespace std;
int v[31];
int main(){
    int n;
    long long w;
    cin >> n >> w;
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int f,s;
    if(n%2==1){
        f=n/2+1;
        s=n/2;
    }else{
        f=n/2;
        s=n/2;
    }
    int tmp1=0;
    int tmp2=0;
    long long left[1000000];
    memset(left,0,sizeof(left));
    long long right[1000000];
    memset(right,0,sizeof(right));
    for(int i=0;i<(1<< f);i++){
        for(int j=0;j<n;j++){
            if((i>>j)&1){
                left[i]+=v[j];
            }
        }
    }
    for(int i=0;i<(1 << s);i++){
        for(int j=0;j<n;j++){
            if((i>>j)&1){
                right[i]+=v[j+f];
            }
        }
    }
    sort(right,right+(1<<s));
    int ans=0;
    for(int i=0;i<(1<<f);i++){
        long long rest=w-left[i];
        int tmp3=-1;
        int l=0;
        int r=(1<<s)-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(right[mid]<=rest){
                tmp3=max(tmp3,mid);
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        ans+=(tmp3+1);
    }
    cout << ans << endl;
    return 0;
}
