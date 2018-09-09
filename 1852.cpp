#include <iostream>
#include <stdio.h>
using namespace std;
int t,n,longn;
int l[1000000];
int main(){
	cin >> t;
	for(int i=0;i<t;i++){
		scanf("%d %d",&longn,&n);
		int min_ans=-1,max_ans=-1;
		for(int j=0;j<n;j++){
			scanf("%d",&l[j]);
			min_ans=max(min_ans,min(l[j],longn-l[j]));
			max_ans=max(max_ans,max(l[j],longn-l[j]));
		}
		cout << min_ans << " " << max_ans << endl;
	}
}
