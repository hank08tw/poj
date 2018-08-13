#include <iostream>
using namespace std;
int n,k,m;
struct smat{
	int array[35][35];
};
struct bmat{
	smat a1;
	smat a2;
	smat a3;
	smat a4;
};
bmat tmp;
bmat f;
smat mult(smat A,smat B){
	smat res;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			res.array[i][j]=0;
			for(int k=1;k<=n;k++){
				res.array[i][j]=(res.array[i][j]+A.array[i][k]*B.array[k][j]%m)%m;
			}
		}
	}
	return res;
}
smat add(smat A,smat B){
        smat res;
        for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
			res.array[i][j]=(A.array[i][j]+B.array[i][j])%m;
                }
        }
        return res;
}
void solve(int n){
	if(n==1)return;
	solve(n/2);
	bmat newtmp;
	newtmp.a1=add(mult(tmp.a1,tmp.a1),mult(tmp.a2,tmp.a3));
	newtmp.a2=add(mult(tmp.a1,tmp.a2),mult(tmp.a2,tmp.a4));
	newtmp.a3=add(mult(tmp.a3,tmp.a1),mult(tmp.a4,tmp.a3));
	newtmp.a4=add(mult(tmp.a3,tmp.a2),mult(tmp.a4,tmp.a4));
	tmp=newtmp;
	if(n%2==1){
		bmat newtmp2;
		newtmp2.a1=add(mult(tmp.a1,f.a1),mult(tmp.a2,f.a3));
        	newtmp2.a2=add(mult(tmp.a1,f.a2),mult(tmp.a2,f.a4));
        	newtmp2.a3=add(mult(tmp.a3,f.a1),mult(tmp.a4,f.a3));
        	newtmp2.a4=add(mult(tmp.a3,f.a2),mult(tmp.a4,f.a4));
		tmp=newtmp2;
	}
}
int main(){
	cin >> n >> k >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> tmp.a1.array[i][j];
			f.a1.array[i][j]=tmp.a1.array[i][j];
			tmp.a2.array[i][j]=0;
			f.a2.array[i][j]=0;
			if(i==j){tmp.a3.array[i][j]=1;tmp.a4.array[i][j]=1;f.a3.array[i][j]=1;f.a4.array[i][j]=1;}
			else {tmp.a3.array[i][j]=0;tmp.a4.array[i][j]=0;f.a3.array[i][j]=0;f.a4.array[i][j]=0;}
		}
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout << tmp.a1.array[i][j] << " ";
			}
			cout << endl;
		}
	}else{
		solve(k);
		smat res;
		res=add(mult(tmp.a3,f.a1),mult(tmp.a4,f.a2));
		for(int i=1;i<=n;i++){
                        for(int j=1;j<=n;j++){
                                cout << res.array[i][j] << " ";
                        }
                        cout << endl;
                }
	}	
}
