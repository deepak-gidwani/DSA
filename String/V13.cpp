#include<bits/stdc++.h>
using namespace std;
//it is useful in multiple patterns to be searched in a txt
// tc=O((m-n)*n)
// ye to direct hashing krdi asli kmp video dekho
void rka(string &str,string &ptr,int m,int n){
    int h1=0,h2=0;
    for(int i=0;i<n;i++){
        h2+=ptr[i];
        h1+=str[i];
    }
    for(int i=0;i<=m-n;i++){
        if(h1==h2){
            cout<<i<<" ";
        }
        h1=h1+str[i+n]-str[i];
    }
}
int main(){
    string txt="abdabcbcabec",pat="abec";
    rka(txt,pat,txt.length(),pat.length());
    return 0;
}