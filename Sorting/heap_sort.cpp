#include<bits/stdc++.h>
using namespace std;
// heap sort is just improvised version of selection sort
int parent(int i){ return (i-1)/2;}
int left(int i){ return 2*i+1;}
int right(int i){ return 2*i+2;}
void maxheapify(int arr[],int i,int n){
    int index=i;
    while(left(i)<n && right(i)<n){
        if(arr[left(i)]<arr[right(i)]){
            swap(arr[index],arr[right(i)]);
            index=right(i);
            i=index;
        }
        else{
            swap(arr[index],arr[left(i)]);
            index=left(i);
            i=index;
        }
    }
}
void buildMaxHeap(int arr[],int n){
    for(int i=(n-2)/2;i>=0;i--){
        maxheapify(arr,i,n);
    }
}
void heapsort(int arr[],int n){  // tc=O(nlogn) as=
    buildMaxHeap(arr,n);
    for(int i=n-1;i>=1;i--){
        swap(arr[0],arr[i]);
        maxheapify(arr,0,i);
    }
}
int main(){
    int arr[]={10,15,50,4,20};
    heapsort(arr,5);
    for(auto x:arr) cout<<x<<" ";
    return 0;
}