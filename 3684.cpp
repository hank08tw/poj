#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
//r>0時不會 WA
using namespace std;
double y[105];
int N,H,R,T;
const double g=10.0;
double calc(int TT){
	double t=sqrt(2*H/g);
	int k=(int)(TT/t);
	if(k%2==0){
		double d=TT-k*t;
		return H-g*d*d/2;
	}else{
		double d=k*k+t-TT;
		return H-g*d*d/2;
	}
}
int main(){
	int c;
	cin >> c;
	while(c--){
		cin >> N >> H >> R >> T;
		for(int i=0;i<N;i++){
			y[i]=calc(T-i);
		}
		sort(y,y+N);
		for(int i=0;i<N;i++)printf("%.2f%c",y[i]+2*R*i/100.0,i+1==N ? '\n':' ');
	}
}
