#include<bits/stdc++.h>
using namespace std;
void patsearching(string &str,string &pat){ // tc=O{(m-n+1)*n} as=O(1)
    int m,n;
    m=str.length();
    n=pat.length();
    for(int i=0;i<=m-n;i++){
        int j;
        for(int j=0;j<n;j++){
            if(pat[j]!=str[i+j]) break;
        }
        if(j==n) cout<<i<<endl;
    }
}
int main(){
    
    return 0;
}