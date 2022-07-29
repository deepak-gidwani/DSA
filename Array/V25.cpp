#include<bits/stdc++.h>
using namespace std;

// moore voting algo

int findmajority(int arr[],int n){
    int res=0,count=1; // first phase n/2 tak baar jo bhi element aaya hoga vo ye phase btaega
    for(int i=1;i<n;i++){
        if(arr[res]==arr[i])
        count++;
        else count--;
        if(count==0){
            count=1;
            res=i;
        }
    }
    count=0; // second phase ye check krega n/2 se jada h ya n/2 hi h
    for(int i=0;i<n;i++){
        if(arr[i]==arr[res]) count++;
    }
    if(count<=n/2) return -1;
    return res;
}
int main(){
   int arr[]={1,2,1,1,1,5,6};
   cout<<findmajority(arr,7);
    return 0;
}