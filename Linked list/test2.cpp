#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int> x;
    x.insert(1);
    x.insert(2);
    x.insert(3);
    // x.insert(4);
    cout<<*(upper_bound(x.begin(),x.end(),2));  // uper and lower bound work only in sorted lists
    set<int>::iterator it = x.begin();
    cout<<x.count(4);
    // it=10;                // sequential data strucutre m it se value chng kr sakte h set vagera m nahi  hash table m gdbd ho jaegi
    // vector<int> arr={1,2,3};
    // auto ite=arr.begin();
    // *ite=12;   it works
    // cout<<*ite;
    return 0;
}