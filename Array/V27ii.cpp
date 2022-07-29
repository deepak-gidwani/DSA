#include<bits/stdc++.h>
using namespace std;
bool subsum(int arr[],int n,int key){ //work only for positive elements
    int sum=0;
    for(int i=0,j=0;i<n;){
        if(sum<key){
            sum+=arr[i];
            i++;
        }
        while(sum>key){
            sum-=arr[j];
            j++;
        }
        if(sum==key) return true;
    }
    return false;
}
int main(){
    int arr[]={1,4,19,3,10,5};
    cout<<subsum(arr,6,15);
    return 0;
}