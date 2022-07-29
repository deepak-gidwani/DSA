#include<bits/stdc++.h>
using namespace std;
bool check(char a,char b);
bool ispar(string x)
    {
        // Your code here
        stack<char> s; // ya stack<int> s koi bhi use krlo
        for(int i=0;i<x.length();i++){
            if(x[i]=='(' || x[i]=='{' || x[i]=='['){
                s.push(x[i]);
            }
            else{
                if(s.empty()==true) return false;
                else if(check(s.top(),x[i])==false) return false;
                else s.pop();
            }
        }
        if(s.empty()==true) return true;
        return false;
    }
    bool check(char a,char b){
        if((a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']')) return true;
        else return false;
    }
int main(){
    string str="()";
    cout<<ispar(str);
    return 0;
}