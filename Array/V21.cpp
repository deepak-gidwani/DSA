#include<bits/stdc++.h>
using namespace std;
int maxcount(int arr[],int n){
    int res=0,curr=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            curr=0;
        }
        else{
            curr++;
            res=max(res,curr);
        }
    }
    return res;
    // int count=0,res=0,j; // ye sahi chal rha h tc iski O(n) hi h bs iska short version likha h upr
    // for(int i=0;i<n-1;){
    //     if(arr[i]==1 && arr[i+1]==1){
    //         j=i;
    //         while(arr[j]==1){
    //             count++;
    //             j++;
    //         }
    //         res=max(res,count);
    //         count=0;
    //         i=j+1;
    //     }
    //     else i++;
    // }
    // if(res==0){
    //     if(arr[0]==1 || arr[n-1]==1) return 1;
    //     else return 0;
    // }
    // else return res;
}
int main(){
    int arr[]={0,1,1,1,0,1,1};
    cout<<maxcount(arr,7);
    return 0;
}