//凸包模板 graham掃描線o(nlogn) 求最遠頂點枚舉o(n^2)
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#define MAX_N 50005


using namespace std;

const double EPS=1e-10;

double add(double a,double b){
	//if(abs(a+b)<EPS*(abs(a)+abs(b)))return 0;
	return a+b;
}
struct P{
	double x,y;
	P(){}
	P(double x,double y):x(x),y(y){
	}
	P operator + (P p){
		return P(add(x,p.x),add(y,p.y));
	}
	P operator - (P p){
		return P(add(x,-p.x),add(y,-p.y));
	}
	P operator * (double d){
		return P(x*d,y*d);
	}
	double dot(P p){
		return add(x*p.x,y*p.y);
	}
	double det(P p){
		return add(x*p.y,-y*p.x);
	}
};

bool on_seg(P p1,P p2,P q){
	return (p1-q).det(p2-q) == 0 && (p1-q).dot(p2-q) <=0;
}
P intersection(P p1,P p2,P q1,P q2){
	return p1+(p2-p1)*((q2-q1).det(q1-p1)/(q2-q1).det(p2-p1));
}
P point[MAX_N];
bool cmp_x(const P& p, const P& q){
	if(p.x!=q.x)return p.x<q.x;
	return p.y<q.y;
}

vector<P> convex_hull(int n){
	sort(point,point+n,cmp_x);
	int k=0;
	vector<P> qs(n*2);
	//構造凸包上側
	for(int i=0;i<n;i++){
		while(k>1&&(qs[k-1]-qs[k-2]).det(point[i]-qs[k-1])<=0)k--;//只能往右走 不能往前或往左
		qs[k++]=point[i];
	}
	int t=k;
	for(int i=n-2;i>=0;i--){
		while(k>t&&(qs[k-1]-qs[k-2]).det(point[i]-qs[k-1])<=0)k--;
		qs[k++]=point[i];
	}
	//cout << "k: " << k << endl;
	qs.resize(k-1);
	return qs;
}

double dist(P p,P q){
	return (p-q).dot(p-q);
}
int n,tmpx,tmpy;
void solve(){
	vector<P> qs=convex_hull(n);
	//for(int i=0;i<qs.size();i++)cout << qs[i].x << " " << qs[i].y << endl;
	double res=0;
	for(int i=0;i<qs.size();i++){
		for(int j=0;j<i;j++){
			res=max(dist(qs[i],qs[j]),res);
		}
	}
	printf("%.0f\n",res);
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&tmpx,&tmpy);
		point[i].x=tmpx;
		point[i].y=tmpy;
	}
	solve();
	return 0;
}
