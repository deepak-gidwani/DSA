#include<iostream>
using namespace std;
bool sort(int arr[],int n){
    int max=arr[n-1];
    for(int i=0;i<n;i++){
        if(max<arr[i])
        return false;
    }
    return true;
}
int main(){
    int arr[]={8},n;
    n=sizeof(arr)/sizeof(arr[0]);
    cout<<sort(arr,n);
    return 0;
}