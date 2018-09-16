//平面掃描template o(nlogn)
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <vector>
#define MAX_N 40005
using namespace std;
int n;
double R[MAX_N];double X[MAX_N];double Y[MAX_N];
//i是否在j裡面 只需判斷圓心是否在裡面 因為題目說沒有相交的圓
bool inside(int i,int j){
	double dx=X[i]-X[j],dy=Y[i]-Y[j];
	return dx*dx+dy*dy<=R[j]*R[j];
}
void solve(){
	vector<pair<double,int> > events;//first: 圓左邊或右邊的x座標 second: 代表這是幾號圓的左邊或右邊
	for(int i=0;i<n;i++){
		events.push_back(make_pair(X[i]-R[i],i));//左邊
		events.push_back(make_pair(X[i]+R[i],i+n));//右邊
	}
	sort(events.begin(),events.end());//根據events.first(x座標)做sort
	
	set<pair<double,int> > outers;
	vector<int> res;
	for(int i=0;i<events.size();i++){
		int id=events[i].second%n;
		if(events[i].second<n){//左邊
			set<pair<double,int> >::iterator it=outers.lower_bound(make_pair(Y[id],id));//>=這個圓的y座標的的圓
			if(it!=outers.end()&&inside(id,it->second))continue;//y比他大且在同一條掃瞄線上最外層的圓不存在且包括i
			if(it!=outers.begin()&&inside(id,(--it)->second))continue;//y比他小且在同一條掃描線上最外層的圓存在且包括i
			res.push_back(id);
			outers.insert(make_pair(Y[id],id));
		}else{//右邊
			outers.erase(make_pair(Y[id],id));
		}
	}
	sort(res.begin(),res.end());
	printf("%d\n",(int)res.size());
	for(int i=0;i<res.size();i++){
		printf("%d%c",(int)res[i]+1,i+1==(int)res.size() ? '\n' : ' ');
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lf %lf %lf",&R[i],&X[i],&Y[i]);
	}
	solve();
	return 0;
}
