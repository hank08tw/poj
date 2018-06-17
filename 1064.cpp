#include <iostream>
#include <math.h>
#include <stdio.h>
#include <iomanip>
using namespace std;
#define NUM 10005
int n,k;
double rope[NUM];
bool satisfy(double x){
        int num=0;
        for(int i=0;i<n;i++){
                num+=(int)(rope[i]/x);
        }
        return num>=k;
}
int main(){
        cin >> n >> k;
        for(int i=0;i<n;i++){
                scanf("%lf",&rope[i]);
        }
        double lb=0,ub=100000;
	
        for(int i=0;i<100;i++){
                double mid=(lb+ub)/2;
                if(satisfy(mid))lb=mid;
                else ub=mid;
		cout << i << " " << lb << " " << ub << endl;
        }
        //cout << setprecision(2) << ub;
        printf("%.2f\n",floor(ub*100)/100);//題目沒說 但是要無條件捨去
}
