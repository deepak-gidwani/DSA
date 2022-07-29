#include<bits/stdc++.h>
using namespace std;
bool fun(string &s1,string &s2,int n,int m){ //tc=O(m+n)
    int j=0;
    for(int i=0;i<n && j<m;i++){
        if(s1[i]==s2[i]) j++;

    }
    return (j==m);
}

// void fun(string &str,string r,int i,int l){ //tc=O(2^n)
//     if(i==l){
//         cout<<r<<endl;
//         return;
//     }
//     fun(str,r,i+1,l);
//     fun(str,r+str[i],i+1,l);
        
// }
int main(){
    string s1="ABCD",s2="BD";
    
    return 0;
}