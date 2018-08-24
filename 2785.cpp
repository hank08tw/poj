#include <iostream>
#include <stdio.h>
#include <algorithm>
#define MAX 4010
#define MAX2 16000100
using namespace std;
int A[MAX];
int B[MAX];
int C[MAX];
int D[MAX];
int CD[MAX2];
int n;
int search_left(int tar){
	int ans=1000000000;
	int left=0;
	int right=n*n-1;
	while(left<=right){
		int mid=(left+right)/2;
		if(CD[mid]==tar){
			ans=min(ans,mid);
			right=mid-1;
		}else if(CD[mid]<tar){
			left=mid+1;
		}else right=mid-1;
	}
	return ans;
}
int search_right(int tar){
	int ans=-1;
        int left=0;
        int right=n*n-1;
        while(left<=right){
                int mid=(left+right)/2; 
                if(CD[mid]==tar){
                        ans=max(ans,mid);
			left=mid+1;
                }else if(CD[mid]<tar){
                        left=mid+1;
                }else right=mid-1;
        }
        return ans;
}
int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d",&A[i],&B[i],&C[i],&D[i]);
	}
	for(int j=0;j<n;j++){
        	for(int k=0;k<n;k++){
                	CD[j*n+k]=C[j]+D[k];
                      	}
                }
        sort(CD,CD+n*n);
	int tmp;
	int ans=0;
        for(int j=0;j<n;j++){
		for(int k=0;k<n;k++){
			tmp=A[j]+B[k];
			int tmp2=search_right(-tmp)-search_left(-tmp)+1;
			if(tmp2!=-1000000000)ans+=tmp2;
		}
	}
	printf("%d\n",ans);
}
