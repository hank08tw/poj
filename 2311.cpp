#include <iostream>
#include <stdio.h>
#include <cstdio>
//#include <memory.h>
#include <string>
#include <cstring>
#include <string.h>
#include <set>
int dp[205][205];
using namespace std;
int grundy(int w,int h){
	if(dp[w][h]!=-1)return dp[w][h];
	set<int> s;
	for(int i=2;w-i>=2;i++)s.insert(grundy(i,h)^grundy(w-i,h));
	for(int i=2;h-i>=2;i++)s.insert(grundy(w,i)^grundy(w,h-i));
	int res=0;
	while(s.count(res)>0)res++;
	return dp[w][h]=res;
}
int main(){
	int w,h;
	memset(dp,-1,sizeof(dp));
	while(~scanf("%d%d",&w,&h)){
		int ans=grundy(w,h);
		if(ans)puts("WIN");
		else puts("LOSE");
	}
	return 0;
}
