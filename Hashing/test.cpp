#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_map<int,int> s;
    s[0]=0;
    s[1]=1;
    s[2]=2;
    s[4]=5;
    s[4]=10;
    s.insert({4,11});
    cout<<s[4];
    // vector<int> z;
    // for(int i=0;i<10;i++){
    //     z.push_back(i);
    // }
    // z.resize(16,-1);
    // cout<<z.size()<<" "<<z.capacity();
    // for(int i=10;i<32;i++){
    //     if(z[i%16]==5) cout<<"yes";
    //     cout<<z[i%16];
        
    // }
    return 0;
}