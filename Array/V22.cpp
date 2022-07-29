#include<bits/stdc++.h>
using namespace std;
int maxSumSubarray(int arr[],int n){
    int maxEnding=arr[0],res=arr[0]; // kadane algorithm
    for(int i=1;i<n;i++){
        maxEnding=max(maxEnding+arr[i],arr[i]);
        res=max(res,maxEnding);
    }
    return res;
    // int counter=arr[0],res=arr[0]; // ye kuch test cases m nahi chlega like this {2,3,-8,7,-1,2,3}
    // for(int i=1;i<n;i++){
    //     counter+=arr[i];
    //     res=max(res,counter);
    //     if(counter<res) counter=0;
    // }
    // return res;
}
int main(){
    int arr[]={-3,8,-2,4,-5,6};
    cout<<maxSumSubarray(arr,6);
    return 0;
}