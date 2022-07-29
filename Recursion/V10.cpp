#include<iostream>
using namespace std;
bool check(string &str,int start,int end){
    if(start>=end) return true;
    else if(str[start]==str[end] && check(str,++start,--end)) 
    return true;
}
int main(){
    string n;
    getline(cin,n);
    int a = n.length();
    
    cout<<check(n,0,a-1);
    return 0;
}