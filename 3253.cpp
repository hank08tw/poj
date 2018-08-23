#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
long long x[20005];
using namespace std;
int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)cin >> x[i];
	sort(x+1,x+n+1);
	unsigned long long ans=0;
	priority_queue<int,vector<int>,greater<int> > que;//greater代表min heap
	for(int i=1;i<=n;i++)que.push(x[i]);
	while(que.size()>1){
		int first,second;
		first=que.top();
		que.pop();
		second=que.top();
		que.pop();
		ans+=(first+second);
		que.push(first+second);
	}
	printf("%llu\n",ans);
}
/*
#include <iostream>
#include <vector>
#include <cstdlib>
#define NUM 100001
using namespace std;
void mergesort(int left,int right,int* data){
    if(left==right)return;
    int mid=(left+right)/2;
    mergesort(left,mid,data);
    mergesort(mid+1,right,data);
    vector<int> leftarray(data+left,data+mid+1);
    vector<int> rightarray(data+mid+1,data+right+1);
    int l=0;
    int r=0;
    for(int i=left;i<=right;i++){
        if((l<leftarray.size ()&&r<rightarray.size ()&&leftarray[l]<=rightarray[r])||(r==rightarray.size ())){data[i]=leftarray[l++];}
        else{
            data[i]=rightarray[r++];
        }
    }
}
int main(){
    int N;
    int data[NUM];
    long long cost=0;
    //while(true){
        scanf("%d",&N);
        //if(N==0)break;
        for(int i=1;i<=N;i++){
            scanf("%d",&data[i]);
        }
        mergesort(1,N,data);
        //for(int i=1;i<=N;i++)cout << data[i] << " ";
        //cout << endl;
        vector<long long> data2;
        int data_pos=1,data2_pos=0;
        long long tmp1=-1,tmp2=-1;
        while(!(data_pos==N+1&&data2_pos==data2.size ()-1&&tmp1==-1)){
            if(tmp1==-1){
                if(data_pos<N+1&&data2_pos<data2.size ()){
                    if(data[data_pos]<=data2[data2_pos]){
                        tmp1=data[data_pos++];
                    }
                    else{
                        tmp1=data2[data2_pos++];
                    }
                }
                else if(data_pos==N+1){
                    tmp1=data2[data2_pos++];
                }
                else if(data2_pos==data2.size ()){
                    tmp1=data[data_pos++];
                }
            }
            else{
                if(data_pos<N+1&&data2_pos<data2.size ()){
                    if(data[data_pos]<=data2[data2_pos]){
                        tmp2=data[data_pos++];
                    }
                    else{
                        tmp2=data2[data2_pos++];
                    }
                }
                else if(data_pos==N+1){
                    tmp2=data2[data2_pos++];
                }
                else if(data2_pos==data2.size ()){
                    tmp2=data[data_pos++];
                }
            }
            if(tmp1!=-1&&tmp2!=-1){
                cost+=tmp1;
                cost+=tmp2;
                data2.push_back (tmp1+tmp2);
                tmp1=-1;
                tmp2=-1;
            }
        }
        cout << cost << endl;
        cost=0;
    //}
}
*/
