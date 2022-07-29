#include<bits/stdc++.h>
using namespace std;
void cycle_sort(int arr[],int n){
    for(int cs=0;cs<n-1;cs++){
        int item=arr[cs];
        int pos=cs;
        for(int i=cs+1;i<n;i++){
            if(arr[i]<item){
                pos++;
            }
        }
        if(pos==cs) continue;
        while(arr[pos]==item) pos++;
        swap(item,arr[pos]);
        while(pos!=cs){ 
            // cout<<"check";
            pos=cs;
            for(int i=cs+1;i<n;i++){
                if(arr[i]<item){
                    pos++;
                }
            }
            while(arr[pos]==item) pos++;
            swap(item,arr[pos]);
        }
    }
}
int main(){
    int arr[]={4,4,0,1,3,4};
    cycle_sort(arr,6);
    for(auto x:arr) cout<<x<<" ";
    return 0;
}