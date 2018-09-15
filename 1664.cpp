#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
using namespace std;
int t,m,n;
unsigned long long dp[20][20];
int main(){
	cin >> t;
	for(int i=0;i<t;i++){
		cin >> m >> n;
		for(int j=0;j<=m;j++){
			dp[j][1]=1;
		}
		for(int j=1;j<=n;j++){
			dp[1][j]=1;
			dp[0][j]=1;
		}
		for(int j=2;j<=m;j++){
			for(int k=2;k<=n;k++){
				if(k>j){
					dp[j][k]=dp[j][k-1];
				}else{
					dp[j][k]=dp[j][k-1]+dp[j-k][k];
				}
			}
		}
		cout << dp[m][n] << endl;
	}
}
