#include <iostream>
#include <algorithm>
using namespace std;
int r,n;
int x[1005];
int main(){
	while(cin >> r >> n){
		if(r==-1&&n==-1)break;
		for(int i=1;i<=n;i++){
			cin >> x[i];
		}
		sort(x+1,x+n+1);
		int ans=0;
		int handle=1;
		while(handle<n+1){
			//cout << ":";
			//int left=x[handle];
			//int right=x[handle]+2*r;
			//cout << l << " " << r << endl;
			int mid=handle;
			int tmp=handle+1;
			while(tmp<n+1&&x[tmp]<=x[handle]+r){
				mid=tmp;
				tmp++;
			}
			while(x[handle]>=x[mid]-r&&x[handle]<=x[mid]+r){
				handle++;
			}
			ans++;
		}
		cout << ans << endl;
	}
}
