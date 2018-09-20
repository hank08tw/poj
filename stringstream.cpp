#include <iostream>
#include <sstream>
using namespace std;
int main(){
	string s;
	int a;
	double b;
	string c;
	istringstream iStream;
	s="123 4.15 abc";
	iStream.str(s);
	iStream >> a >> b >> c;
	cout << a << " " << b << " " << c << endl;

	ostringstream oStream;
	string s2;
	oStream << a << b << c;
	s2=oStream.str();
	cout << s2 << endl;
	return 0;
}
