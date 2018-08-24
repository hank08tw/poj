#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#define MAX 5005
using namespace std;
bool ff[MAX];
int f[MAX];
int main(){
	int n;
	char tmp;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> tmp;
		if(tmp=='F')ff[i]=true;
		else ff[i]=false;
	}
	int m=n;
	int kk=1;
	for(int i=1;i<=n;i++){//choices for k
		memset(f,0,sizeof(f));
		int ans=0;//轉換次數
		int sum=0;//sum總合
		int k=i;
		if(!ff[0]){f[0]=1;ans++;if(k>1)sum++;}
		for(int j=1;j<n-k+1;j++){
			if(sum%2==1){
				if(k>1&&j-k+1>=0){sum-=f[j-k+1];}
				if(ff[j]){
					f[j]=1;
					if(k>1)sum++;
					ans++;
				}
			}else{
				if(k>1&&j-k+1>=0){sum-=f[j-k+1];}
				if(!ff[j]){
                                        f[j]=1;
                                        if(k>1)sum++;
                                        ans++;
                                }
			}
		}
		for(int j=n-k+1;j<n;j++){
			if((sum%2==1&&ff[j])||(sum%2==0&&!ff[j])){ans=2000000000;break;}
			if(k>1&&j-k+1>=0)sum-=f[j-k+1];
		}
		if(ans<m){
			kk=k;
			m=ans;
		}
	}
	cout << kk << " " << m << endl;
}
