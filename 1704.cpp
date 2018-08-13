#include <iostream>
#include <algorithm>
using namespace std;
int a[1005];
int main(){
	int t,n;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=1;i<=n;i++)cin >> a[i];
		sort(a,a+n+1);
		int ans=0;
		if(n%2==1){
			ans^=(a[1]-1);
			for(int i=3;i<=n;i+=2){
				ans^=(a[i]-a[i-1]-1);
			}
		}else{
			for(int i=2;i<=n;i+=2){
				ans^=(a[i]-a[i-1]-1);
			}
		}
		if(ans==0){
			cout << "Bob will win\n";	
		}else{
			cout << "Georgia will win\n"; 
		}
	}
}
