#include<bits/stdc++.h>
using namespace std;
int diff1(int arr[],int n){ // tc= O(n*n)
    int mx=INT_MIN;
    vector<int> a;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            
            mx=max(arr[j]-arr[i],mx);
            
        }
        // a.push_back(max);
        // max=INT_MIN;
    }
    return mx;
    // return *max_element(a.begin(),a.end());
}

int diff2(int arr[],int n){ // tc =O(n)
    int res=INT_MIN,mn=arr[0];
    for(int j=1;j<n;j++){
        res=max(res,arr[j]-mn);
        mn=min(mn,arr[j]);
    }
    return res;
}

int main(){
    int arr[]={2,3,10,6,4,8,1};
    // vector<int> b = diff(arr,7);
    // for(auto x:b) cout<<x;
    cout<<diff2(arr,6);
    return 0;
}