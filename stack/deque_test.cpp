#include<bits/stdc++.h>
using namespace std;       // deque is advanced vector
int main(){
    deque<int> dq(1);
    dq[0]=1;
    dq.push_back(2);
    dq.push_front(0);
    for(auto x:dq){
        cout<<x<<" ";
    }
    cout<<endl;
    for(auto x:dq){
        cout<<x<<" ";
    }
    return 0;
}