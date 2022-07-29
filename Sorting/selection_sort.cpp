#include<bits/stdc++.h>
using namespace std;
void selection_sort(int arr[],int n){
    int mn=INT_MAX,index=-1;
    for(int i=0;i<n-1;i++){
        for(int j=i;j<n;j++){
            if(mn>arr[j]){
                mn=arr[j];
                index=j;
            }
        }
        swap(arr[index],arr[i]);
        mn=INT_MAX;
    }
}
int main(){
    int arr[] = {4, 7, 2, 9, 1, 0};
    selection_sort(arr, 6);
    for (auto x : arr)
        cout << x << " ";
    return 0;
}