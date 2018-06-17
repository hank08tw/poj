#include <iostream>
//#include <string.h>
//#include <cstring>
//#include <iomanip>
//#include <stdio.h>
using namespace std;
int mat[9]={2,1,0,2,2,2,0,1,2};
unsigned long long cur[9]={1,0,0,0,1,0,0,0,1};
unsigned long long tmp[9];
void compute(int n){
	if(n==0){
		return;
	}
	if(n==1){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				tmp[i*3+j]=0;
				for(int k=0;k<3;k++){
					tmp[i*3+j]+=cur[i*3+k]*mat[k*3+j];
				}
			}
		}
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				cur[i*3+j]=tmp[i*3+j]%10007;
			}
		}
		return;
	}
	compute(n/2);
        	for(int i=0;i<3;i++){
                        for(int j=0;j<3;j++){
                                tmp[i*3+j]=0;
                                for(int k=0;k<3;k++){
                                        tmp[i*3+j]+=cur[i*3+k]*cur[k*3+j];
                                }
                        }
                }
                for(int i=0;i<3;i++){
                        for(int j=0;j<3;j++){
                                cur[i*3+j]=tmp[i*3+j]%10007;
                        }
                }
	if(n%2==1){
		for(int i=0;i<3;i++){
                        for(int j=0;j<3;j++){
                                tmp[i*3+j]=0;
                                for(int k=0;k<3;k++){
                                        tmp[i*3+j]+=cur[i*3+k]*mat[k*3+j];
                                }
                        }
                }
                for(int i=0;i<3;i++){
                        for(int j=0;j<3;j++){
                                cur[i*3+j]=tmp[i*3+j]%10007;
                        }
                }

	}
		
}
int main(){
	int t,n;
	//scanf("%d",&t);
	cin >> t;
	for(int i=0;i<t;i++){
		//scanf("%d",&n);
		cin >> n;
		compute(n-1);
		//printf("%llu\n",(cur[0]*2+cur[1]*2)%10007);
		cout << (cur[0]*2+cur[1]*2)%10007 << endl;	
		//memset(cur,0,sizeof(cur));
		for(int j=0;j<9;j++)cur[j]=0;
		cur[0]=1;
		cur[4]=1;
		cur[8]=1;
	}
}
