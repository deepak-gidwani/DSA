#include<bits/stdc++.h>
using namespace std;
void insertion_sort(int arr[],int n){
    for(int i=1;i<n;i++){
        // int x=arr[i];
        int j=i;
        if(arr[i]>arr[i-1]) continue;
        while(arr[j]<arr[j-1] && j>=1){
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
}
int main(){
    int arr[] = {4, 7, 2, 9, 1, 0};
    insertion_sort(arr, 6);
    for (auto x : arr)
        cout << x << " ";
    return 0;
}