#include <iostream>
using namespace std;
int main(){
	int num[100005];
	int t,s,n;
	cin >> t;
	while(t--){
		cin >> n >> s;
		for(int i=0;i<n;i++){
			cin >> num[i];
		}
		int start=0;
		int last=0;
		int sum=0;
		int result=n+1;
		while(last<n&&sum<s){
			sum+=num[last++];
		}
		//cout << "sum: " << sum << endl;
		if(sum<s){
			cout << "0" << endl;
			//cout << "la" << endl;
		}else{
			while(start<n){
				sum-=num[start++];
				while(last<n&&sum<s){
					sum+=num[last++];
				}
				if(sum>=s)result=min(result,last-start);
				//cout << "sum: " << sum << " result: " << result << endl;
			}
			cout << result << endl;		
		}
	}	
}
