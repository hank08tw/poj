#include <iostream>
#include <stdio.h>
#include <cstdio>
using namespace std;
//WA
//區間修改 區間詢問
struct node{
    int l,r;
    int lch,rch;
    long long  sum;
	long long add_val;
};
//題目的陣列大小好像不夠大
int N[100005];
node tree[400005];
int contruct(int n,int l,int r){
	//tree[n].add_val=0;
    tree[n].l=l;
    tree[n].r=r;
    if(l==r-1){
        tree[n].sum=N[l];
        return N[l];
    }
    int lch=tree[n].lch=n*2;
    int rch=tree[n].rch=n*2+1;
    int left=contruct(lch,l,(int)(l+r)/2);
    int right=contruct(rch,(int)(l+r)/2,r);
    tree[n].sum=left+right;
    return tree[n].sum;
}
void revise(int a,int b,int val,int n){
    if(a<=tree[n].l&&tree[n].r<=b){
        tree[n].add_val+=val;
        return;
    }/*else if(tree[n].r<=a||b<=tree[n].l)return;
	else{
		revise(a,b,val,tree[n].lch);
		revise(a,b,val,tree[n].rch);
		//tree[n].sum=tree[tree[n].lch].sum+tree[tree[n].lch].add_val*(tree[tree[n].lch].r-tree[tree[n].lch].l)+tree[tree[n].rch].sum+tree[tree[n].rch].add_val*(tree[tree[n].rch].r-tree[tree[n].rch].l);
		tree[n].sum+=val*(min(b,tree[n].r)-max(a,tree[n].l));
	}*/
	else if(tree[n].l<b&&a<tree[n].r){
		tree[n].sum+=(min(b,tree[n].r)-max(a,tree[n].l))*val;
		revise(a,b,val,tree[n].lch);
		revise(a,b,val,tree[n].rch);
	}
}
long long query(int a,int b,int n){
    if(tree[n].l>=a&&tree[n].r<=b){
        return tree[n].sum+tree[n].add_val*(tree[n].r-tree[n].l);
    }
	if(b<=tree[n].l||tree[n].r<=a)return 0;
	return query(a,b,tree[n].lch)+query(a,b,tree[n].rch)+tree[n].add_val*(min(tree[n].r,b)-max(tree[n].l,a));
}
int main() {
    int n,q,l,r,x;
	char choice;
    scanf("%d %d",&n,&q);
    for(int i=0;i<n;i++){
        scanf ("%d",&N[i]);
    }
    contruct(1,0,n);
    for(int i=0;i<q;i++){
        cin >> choice;
        if(choice=='C'){
		scanf("%d %d %d",&l,&r,&x);
            	revise(l-1,r,x,1);
        }
        else{
		scanf("%d %d",&l,&r);
            	printf("%lld\n",query(l-1,r,1));

        }
	/*
	for(int j=1;j<=15;j++){cout << tree[j].max_val << " ";}
	cout << endl;
	for(int j=1;j<=15;j++){cout << tree[j].add_val << " ";}
        cout << endl;
	*/
    }
    return 0;
}
