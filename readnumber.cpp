#include <iostream>
#include <fstream>
using namespace std;
int main(){
	ifstream iFile;
	iFile.open("numbers.txt");
	int tmp;
	int sum=0;
	while(iFile){
		iFile >> tmp;//insertion operator and input stream will dismiss spaces
		if(iFile){
			sum+=tmp;
		}
	}
	cout << sum << endl;
	return 0;
}
