#include <iostream>
using namespace std;
int main(){
	int n;
	while(cin >> n){
		if(n==0)break;
		if(n>2)cout << "Bob" << endl;
		else cout << "Alice" << endl;
	}
}
