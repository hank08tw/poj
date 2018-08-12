#include <iostream>
#define swap(a,b,tmp) tmp=a,a=b,b=tmp
using namespace std;
unsigned long long tmp;
bool gcd(unsigned long long a,unsigned long long b){
	if(b<a)swap(a,b,tmp);
	if(b%a==0)return true;
	if(b-a>a)return true;
	return !gcd(b-a,a);
}
int main(){
	unsigned long long a,b;
	while(true){
		cin >> a >> b;
		if(a==0&&b==0)break;
		bool win=gcd(a,b);
		if(win)cout << "Stan wins" << endl;
		else cout << "Ollie wins" << endl;
	}
}
