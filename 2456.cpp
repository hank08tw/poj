#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
int x[100005];
bool C(int cur){
	int last=0;
	int num=m-1;
	if(num==0)return true;
	for(int i=1;i<n;i++){
		if(x[i]-x[last]>=cur){
			num--;
			last=i;
		}
		if(num==0)return true;
	}
	return false;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&x[i]);
	}
	sort(x,x+n);
	int lb=0,ub=1000000000;
	int ans=0;
	while(ub>=lb){
		//cout << lb << " " << ub << endl;
		int mid=(lb+ub)/2;
		if(C(mid)){
			lb=mid+1;
			ans=max(ans,mid);
		}
		else ub=mid-1;
	}
	printf("%d\n",ans);
}
