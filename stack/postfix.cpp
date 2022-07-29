#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<int> x;
    x.push(1);
    x.push(2);
    x.push(3);
    x.top()=4;
    cout<<x.top()<<" "<<x.size();
    return 0;
}