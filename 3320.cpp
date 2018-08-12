#include <iostream>
#include <set>
#include <map>
using namespace std;
long long num[1000005];
set<int> all;
map<long long,int> m;
int main(){
	int p;
	cin >> p;
	for(int i=0;i<p;i++){
		cin >> num[i];
		all.insert(num[i]);
		m[num[i]]=0;
	}
	const int size=all.size();
	int n=0,start=0,end=0;
	while(n<size&&end<p){
		if(m[num[end]]==0){
			n++;
		}
		m[num[end]]++;	
		end++;
	}
	
	int result=end-start;
	while(start<p){
			if(m[num[start]]==1){
				n--;
			}
			m[num[start]]--;
			start++;
			while(n<size&&end<p){
				if(m[num[end]]==0){
					n++;
				}
				m[num[end]]++;
				end++;
			}
			if(n>=size){
				result=min(result,end-start);}
	}
	cout << result << endl;
}
