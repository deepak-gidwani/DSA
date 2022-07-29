#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<int> x;
    x.push(1);
    x.push(2);
    x.push(3);
    x.back()=4;
    cout<<x.back();
    return 0;
}