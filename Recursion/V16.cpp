#include<bits/stdc++.h>
using namespace std;
void subset(vector<int> &arr,vector<int> a,int digit,int i=0){
    if(digit==i){
        for(auto x:a) cout<<x<<" ";
        cout<<endl;
        return;
    }
    subset(arr,a,digit,i+1);
    a.push_back(arr[i]);
    subset(arr,a,digit,i+1);
}
int main(){
    vector<int> arr{1,2,3},a;
    int sum=4;
    int digit=3;
    subset(arr,a,digit,0);
    return 0;
}