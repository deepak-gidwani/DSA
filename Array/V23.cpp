#include<bits/stdc++.h>
using namespace std;
int longestEvenOdd(int arr[],int n){
    int count=1,res=1;
    int i=0;
    while(i<n-1){
        if((arr[i]%2==0 && arr[i+1]%2!=0) || (arr[i]%2!=0 && arr[i+1]%2==0)){
            count++;
            i++;
            res=max(res,count);
        }
        else{
            i++;
            count=1;
        }
    }
    return res;
}
int main(){
    int arr[]={10,12,14,7,8};
    cout<<longestEvenOdd(arr,5);
    return 0;
}