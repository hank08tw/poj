#include <iostream>
//bellman_ford o(ve)
using namespace std;
#define MAX_E 100
#define MAX_V 100
#define INF 2147483647
struct edge{int from,to,cost;};

edge es[MAX_E];

int d[MAX_V];
int V,E;
bool find_neg_loop(){
	memset(d,0,sizeof(d));
	for(int i=0;i<V;i++){
		for(int j=0;j<E;j++){
			edge e=es[j];
			if(d[e.to]>d[e.from]+e.cost){
				e.to=d[e.from]+e.cost;
				//V個點最短路最長長度是|v|-1 每次至少更新一條邊（一個d[i]）如果第V次還在更新代表存在負環
				if(i==V-1){
					return true;
				}
			}
		}
	}
	return false;
}
void shortest_path(int s){
	for(int i=0;i<V;i++)d[i]=INF;
	d[s]=0;
	while(true){
		bool update=false;
		for(int i=0;i<E;i++){
			edge e=es[i];
			if(d[e.from]!=INF&&d[e.from]+e.cost <d[e.to]){
				d[e.to]=d[e.from]+e.cost;
			}
		}
		if(!update)break;
	}
}
int main(){
	return 0;
}
