#include<iostream>
using namespace std;
void rev(int arr[],int n){
    for(int i=0;i!=n/2;i++){
        int temp=arr[i];
        arr[i]=arr[n-i-1];
        arr[n-i-1]=temp;
    }
}
int main(){
    int arr[]={2,5,3,7,9},n;
    n=5;
    rev(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}