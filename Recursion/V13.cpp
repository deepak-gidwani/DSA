#include<iostream>
using namespace std;
void subset(string &str,string curr="",int i=0){
    if(str.length()==i){
        cout<<curr<<endl;
        return;
    }
    subset(str,curr,i+1);
    // curr=curr+str[i]; this is also correct
    subset(str,curr+str[i],i+1);
}
int main(){
    string str;
    cin>>str;
    subset(str);
    return 0;
}