#include<bits/stdc++.h>
using namespace std;
void check(vector<int> *b){ // vector ka pointer h ye // ye sb mt chedo normal apna kaam kro
    // cout<<b;
    b->push_back(30);
    // return b;
    // str[3]='f';
    // cout<<str;
}
int main(){
    vector<int> a;
    // cout<<&a;
    check(&a);
    cout<<a[0];
    // string str="hello";
    // str[2]='h';
    // check(str);
    // cout<<str;
    return 0;
}