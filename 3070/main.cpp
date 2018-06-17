#include <iostream>
using namespace std;
struct matrix{
    int a,b,c,d;
    matrix(int a,int b,int c,int d){
        this->a=a;
        this->b=b;
        this->c=c;
        this->d=d;
    }
};
matrix binary(long long n){
    if(n==1){
        matrix tmp(1,1,1,0);
        return tmp;
    }
    else if(n%2==0){
        matrix tmp=binary(n/2);
        matrix newmat((tmp.a*tmp.a+tmp.b*tmp.c)%10000,(tmp.a*tmp.b+tmp.b*tmp.d)%10000,(tmp.c*tmp.a+tmp.d*tmp.c)%10000,(tmp.c*tmp.b+tmp.d*tmp.d)%10000);
        return newmat;
    }
    else{
        matrix tmp=binary(n/2);
        matrix newmat((tmp.a*tmp.a+tmp.b*tmp.c)%10000,(tmp.a*tmp.b+tmp.b*tmp.d)%10000,(tmp.c*tmp.a+tmp.d*tmp.c)%10000,(tmp.c*tmp.b+tmp.d*tmp.d)%10000);
        matrix newmat2(newmat.a+newmat.b,newmat.a,newmat.c+newmat.d,newmat.c);
        return newmat2;
    }
}
int main() {
    long long n;
    while(scanf("%lld",&n)){
        if(n==-1)break;
        if(n==0)printf("0\n");
        else if(n<=2)printf("1\n");
        else{
            matrix mat=binary(n-2);
            printf("%d\n",(mat.a+mat.b)%10000);
        }
    }
    return 0;
}