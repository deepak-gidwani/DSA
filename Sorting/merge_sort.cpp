#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int low,int mid,int high){   // theta(n) for both tc & as sirf yehi fxn ki
    int j=mid+1;
    int x=low;
    int k=low;
    vector<int> ans;
    while(low<=mid && j<=high){    // intersection and union of two sorted array wala ques issi logic se ho sakta h
        if(arr[low]>=arr[j]){
            ans.push_back(arr[j]);
            j++;
        }
        else{
            ans.push_back(arr[low]);
            low++;
        }
    }
    while(low<=mid){
        ans.push_back(arr[low]);
        low++;
    }
    while(j<=high){
        ans.push_back(arr[j]);
        j++;
    }
    for(int i=0;i<ans.size();i++){
        arr[i+x]=ans[i];
    }
    // for(auto x:ans) cout<<x<<" "; 
}
void mergesort(int arr[],int low,int high){  // tc=theta(nlogn) and as=theta(n)
    if(low<high){
        int mid=low+(high-low)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
int main(){
    int arr[]={10,5,30,15,7};
    mergesort(arr,0,4);
    for(int i=0;i<5;i++) cout<<arr[i]<<" ";
    return 0;
}