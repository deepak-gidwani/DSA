#include<bits/stdc++.h>
using namespace std;
void freq(int arr[],int n){
    int i=1,freq=1;
    while(i<n){
        while(i<n && arr[i]==arr[i-1]){
            freq++;
            i++;
        }
        cout<<arr[i-1]<<" "<<freq+1<<endl;
        freq=1;
        i++;
    }
    if(n==1 || arr[n-1]!=arr[n-2]){
        cout<<arr[n-1]<<" "<<1;
    }
}
int main(){
    int arr[]={10,10,10,20,20,30};
    freq(arr,6);
    return 0;
}