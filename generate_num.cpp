#include <iostream>
#include <fstream>
using namespace std;
int main(){
	ofstream oFile;
	oFile.open("numbers.txt");
	for(int i=0;i<10;i++){
		for(int j=1;j<=10;j++){
			oFile << i*10+j << " ";
		}
		oFile << endl;
	}
	oFile.close();
	return 0;
}
