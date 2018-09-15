#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
long long dp_first[1000001];
long long dp_second[1000001];
int a[1001];
const int mod=1e6;
int t,A,s,b,tmp;
int main(){
	scanf("%d %d %d %d",&t,&A,&s,&b);
	memset(a,0,sizeof(a));
	memset(dp_first,0,sizeof(dp_first));
	memset(dp_second,0,sizeof(dp_second));
	for(int i=0;i<A;i++){
		scanf("%d",&tmp);
		a[tmp]++;
	}
	for(int i=0;i<=A;i++){
		dp_first[i]= a[1]>=i ? 1 : 0;
	}
	for(int i=2;i<=t;i++){
		dp_second[0]=1;
		dp_second[1]=i;
		for(int j=2;j<=A;j++){
			if((j-1-a[i])>=0){
				dp_second[j]=(dp_second[j-1]+dp_first[j]-dp_first[j-1-a[i]])%mod;//+mod保證dp_second[j]是正數
			}else{
				dp_second[j]=(dp_second[j-1]+dp_first[j])%mod;
			}
		}
		for(int j=0;j<=A;j++){
			dp_first[j]=dp_second[j];
		}
	}
	int ans=0;
	for(int i=s;i<=b;i++){
		ans=(ans+dp_first[i])%mod;
	}
	cout << (ans+mod)%mod << endl;//也可以最後再加
}
