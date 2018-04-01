#include <iostream>
#include <deque>//引入雙端隊列 雙端都可以push跟pop 且複雜度都是o(1) 也可以用 雙向linked list實作
using namespace std;
//單調隊列優化 前面的元素會先滑出去
int main() {
    int n,k;
    deque<int> maxdeque,mindeque;
    int data[1000005];
    while(cin >> n >> k){
        for(int i=0;i<n;i++){
            scanf("%d",&data[i]);
        }
        //找minimum的時候只關心最小值 所以維護一個單調遞增的deque 前面捨棄的元素檢查是不是最小值（deque前端）如果是就pop掉 加入元素時從後端加入 把deque後端大於(等於不要pop掉)加入元素的元素都pop掉（因為不會用到）先前端檢查要不要pop掉在檢查後端
        mindeque.push_back (data[0]);
        for(int i=1;i<k;i++){
            while(!mindeque.empty()&&mindeque.back ()>data[i]){
                mindeque.pop_back ();
            }
            mindeque.push_back (data[i]);
        }
        printf("%d ",mindeque.front());
        for(int i=k;i<n;i++){
            //檢查丟掉的元素是不是當前deque前端的元素（最小值）如果是的話就把元素pop掉
            if(data[i-k]==mindeque.front()){
                mindeque.pop_front ();
            }
            while(!mindeque.empty()&&mindeque.back ()>data[i]){
                mindeque.pop_back ();
            }
            mindeque.push_back (data[i]);
            printf("%d ",mindeque.front());
        }
        cout << endl;
        //同理
        maxdeque.push_back (data[0]);
        for(int i=1;i<k;i++){
            while(!maxdeque.empty()&&maxdeque.back ()<data[i]){
                maxdeque.pop_back ();
            }
            maxdeque.push_back (data[i]);
        }
        printf("%d ",maxdeque.front());
        for(int i=k;i<n;i++){
            //檢查丟掉的元素是不是當前deque前端的元素（最大值）如果是的話就把元素pop掉
            if(data[i-k]==maxdeque.front()){
                maxdeque.pop_front ();
            }
            while(!maxdeque.empty()&&maxdeque.back ()<data[i]){
                maxdeque.pop_back ();
            }
            maxdeque.push_back (data[i]);
            printf("%d ",maxdeque.front());
        }
        cout << endl;
        maxdeque.clear();
        mindeque.clear();
    }
    return 0;
}