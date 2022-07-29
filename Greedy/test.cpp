#include<bits/stdc++.h>
using namespace std;
int main(){
    string str="papp";
    if(str.find("pap")!=string::npos){
        cout<<string::npos<<" "<<str.find("pap");
    }
    else{
        cout<<string::npos<<" "<<str.find("hap")<<"d";
    }
    return 0;
}