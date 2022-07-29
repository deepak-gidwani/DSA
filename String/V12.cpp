#include<bits/stdc++.h>
using namespace std;        // improved naive menthod
void patsearching(string &str,string &ptr){ // this is only for distinct element in ptr its tc is theta n
    int m,n;
    m=str.length();
    n=ptr.length();
    for(int i=0;i<=m-n;){
        int j;
        for(int j=0;j<n;j++){
            if(ptr[j]!=str[i+j]) break;
        }
        if(j==n) cout<<i<<endl;
        if(j==0) i++;
        else i=i+j;
    }
}
int main(){
    
    return 0;
}