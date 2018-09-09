#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stdio.h>
#include <string>
using namespace std;
typedef long long ll;
const int MAX=100005;
int N,Q;
int A[MAX];
int T[MAX];
int L[MAX],R[MAX],X[MAX];
//segment tree區間修改 區間求和 主要就是每個點要記錄lazy tag 那個恰好完全包括點改的值 modify的時候要先pushdown把之前的更改往下壓 讓他們不在用到 push up最後要把自己的sum更新
const int BIG=(1 << 18)-1;
ll data[BIG],datb[BIG],datc[BIG];//a是add value b是最大值 c是改的值 a,c都算是lazy tag
void push(int k,int lson,int rson){
	if(datc[k]>0){
		datb[k]=datc[k];
		if(lson>=0)datc[lson]=datc[k];data[lson]=0;
		if(rson>=0)datc[rson]=datc[k];data[lson]=0;
		datc[k]=0;
	}
	if(data[k]>0){
		datb[k]+=data[k];
		if(lson>=0)data[lson]+=data[k];
		if(rson>=0)data[rson]+=data[k];
		data[k]=0;
	}
}
void add(int a,int b,int x,int k,int l,int r){
	int lson=k*2+1;int rson=k*2+2;
	if(l==r){
		lson=rson=-1;
	}
	push(k,lson,rson);
	if(a<=l&&r<=b){
		data[k]+=x;//當前區間在目標區間裡面 add更新
	}else if(l<b&&a<r){
		//datb[k]+=(min(b,r)-max(a,l))*x;//sum更新
		add(a,b,x,k*2+1,l,(l+r)/2);
		add(a,b,x,k*2+2,(l+r)/2,r);
		ll x1=(datc[lson]>0 ? datc[lson] : datb[lson])+data[lson];
		ll x2=(datc[rson]>0 ? datc[rson] : datb[rson])+data[rson];
		datb[k]=max(x1,x2);
	}
}

void modify(int a,int b,int x,int k,int l,int r){
	int lson=k*2+1,rson=k*2+2;
	if(l==r){
		lson=rson=-1;
	}
	push(k,lson,rson);
	if(a<=l&&r<=b){
                datc[k]=x;//當前區間在目標區間裡面 change更新
        }else if(l<b&&a<r){
                //datb[k]+=(min(b,r)-max(a,l))*x;//sum更新
                modify(a,b,x,k*2+1,l,(l+r)/2);
                modify(a,b,x,k*2+2,(l+r)/2,r);
                ll x1=(datc[lson]>0 ? datc[lson] : datb[lson])+data[lson];
                ll x2=(datc[rson]>0 ? datc[rson] : datb[rson])+data[rson];
                datb[k]=max(x1,x2);
        }

}
ll sum(int a,int b,int k,int l,int r){//查找sum
	if(b<=l||r<=a){
		return 0;
	}else if(a<=l&&r<=b){//當前區間在目標區間裡面 回傳add and sum
		return data[k]*(r-l)+datb[k];
	}else{
		ll res=(min(b,r)-max(a,l))*data[k];
		res+=sum(a,b,k*2+1,l,(l+r)/2);
		res+=sum(a,b,k*2+2,(l+r)/2,r);
		return res;
	}
}
ll query(int a,int b,int k,int l,int r){//查找max
	int lson=k*2+1,rson=k*2+2;
        if(l==r){
                lson=rson=-1;
        }
        push(k,lson,rson);
	if(a<=l&&r<=b){
                return datb[k];//當前區間在目標區間裡面 add更新 
        }else if(l<b&&a<r){
                ll x1=query(a,b,lson,l,(l+r)/2);
                ll x2=query(a,b,rson,(l+r)/2,r);
                return max(x1,x2)+data[k];
        }
	return -1;
}
void solve(){
	for(int i=0;i<N;i++){
		add(i,i+1,A[i],0,0,N);
	}
	for(int i=0;i<Q;i++){
		if(T[i]==1){
			add(L[i]-1,R[i],X[i],0,0,N);
		}else if(T[i]==2){
			printf("%lld\n",query(L[i]-1,R[i],0,0,N));
		}else{
			modify(L[i]-1,R[i],X[i],0,0,N);
		}
	}
}
int main(){
	memset(data,0,sizeof(data));
	memset(datb,0,sizeof(datb));
	memset(datc,0,sizeof(datc));
	scanf("%d %d",&N,&Q);
	for(int i=0;i<N;i++){scanf("%d",&A[i]);}
	for(int i=0;i<Q;i++){
		cin >> T[i];
		if(T[i]==1||T[i]==3){
			scanf("%d %d",&L[i],&R[i]);
			scanf("%d",&X[i]);
		}else{
			scanf("%d %d",&L[i],&R[i]);
		}
		//cout << L[i] << R[i] << X[i] << endl;
	}
	solve();
	//cout << data[0] << " " << datb[0] << endl;
	return 0;
}
