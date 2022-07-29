#include<bits/stdc++.h>
using namespace std;
vector<int> fun(string &s1,string &s2){
    int start=0,end=0,i=1,l2;

// ese hi try kr rha tha aaaa jese test case m fail h ye

    vector<int> ans(0);
    while(1){
        start=0,end=0;
    l2=s2.length();
    start=s1.find(s2);
    if(start!=string::npos){
    end=start+l2;
    ans.push_back(start);
    i=end;
    s1.erase(0,end);
    }
    else break;

    }
    return ans;
}
int main(){
    vector<int> ans;
    string s1="zzzzz";
    string s2="zz";
    ans = fun(s1,s2);
    for(auto x:ans) cout<<x<<endl;
    return 0;
}