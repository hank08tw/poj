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
char T[MAX];
int L[MAX],R[MAX],X[MAX];
//segment tree
const int BIG=(1 << 18)-1;
ll data[BIG],datb[BIG];//a是add value b是區間合
void add(int a,int b,int x,int k,int l,int r){
	if(a<=l&&r<=b){
		data[k]+=x;//當前區間在目標區間裡面 add更新
	}else if(l<b&&a<r){
		datb[k]+=(min(b,r)-max(a,l))*x;//sum更新
		add(a,b,x,k*2+1,l,(l+r)/2);
		add(a,b,x,k*2+2,(l+r)/2,r);
	}
}
ll sum(int a,int b,int k,int l,int r){
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
void solve(){
	for(int i=0;i<N;i++){
		add(i,i+1,A[i],0,0,N);
	}
	for(int i=0;i<Q;i++){
		if(T[i]=='C'){
			add(L[i]-1,R[i],X[i],0,0,N);
		}else{
			printf("%lld\n",sum(L[i]-1,R[i],0,0,N));
		}
	}
}
int main(){
	memset(data,0,sizeof(data));
	memset(datb,0,sizeof(datb));
	scanf("%d %d",&N,&Q);
	for(int i=0;i<N;i++){scanf("%d",&A[i]);}
	for(int i=0;i<Q;i++){
		cin >> T[i];
		if(T[i]=='C'){
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
