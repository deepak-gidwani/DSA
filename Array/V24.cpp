#include<bits/stdc++.h>
using namespace std;
int maxCirSubArray(int arr[],int n){
    int res=arr[0];
    for(int i=0;i<n;i++){ // ye O(n*n) wala h, kadane wala alag sol h
        int currmax=arr[i];
        int currsum=arr[i];
        for(int j=1;j<n;j++){
            int index=(i+j)%n;
            currsum+=arr[index];
            currmax=max(currmax,currsum);
        }
        res=max(res,currmax);
    }
    return res;
}
int main(){
    

    return 0;
}