#include <iostream>
using namespace std;
char a[2005];
char ans[2005];
int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	int l=1;
	int r=n;
	for(int i=1;i<=n;i++){
		if(l==r){ans[i]=a[l];}
		else if(a[l]<a[r]){ans[i]=a[l++];}
		else if(a[l]>a[r]){ans[i]=a[r--];}
		else{
			int tmpl=l+1;
			int tmpr=r-1;
			bool haveans=false;
			while(tmpl<=tmpr){
				if(a[tmpl]==a[tmpr]){
					tmpl++;
					tmpr--;
				}else if(a[tmpl]<a[tmpr]){
					ans[i]=a[l++];
					haveans=true;break;
				}else{
					ans[i]=a[r--];
					haveans=true;break;
				}
			}
			if(!haveans){
				ans[i]=a[l++];
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout << ans[i];
		if(i%80==0)cout << endl;
	}
	cout << endl;
}
