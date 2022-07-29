#include<bits/stdc++.h>
using namespace std;
void countingSort(int arr[],int n,int exp){
    int count[10],output[n];
    for(int i=0;i<10;i++){
        count[i]=0;
    }
    for(int i=0;i<n;i++){
        count[(arr[i]/exp)%10]++;
    }
    for(int i=1;i<n;i++){
        count[i]+=count[i-1];
    }
    for(int i=n-1;i>=0;i--){
        output[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}
void radix_sort(int arr[],int n){
    int mx=*(max_element(arr,arr+n));
    for(int exp=1;mx/exp>0;exp*=10){
        countingSort(arr,n,exp);
    }
};
int main(){
    
    return 0;
}