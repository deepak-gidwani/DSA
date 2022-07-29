#include<bits/stdc++.h>
using namespace std;
void algo(int arr[],int l,int h){  // basically array ko char hiso m baat diya
                                  // o se l k 0's, l se mid-1 k 1's, mid se high elements jo abhi hum process kr rhe h
                                  // high+1 se array k end tk 2's
                                  // tc=thata(n) only one traversal, ek aux array bna k naive method bhi h
    int mid=l;
    while(mid<=h){
        if(arr[mid]==1) mid++;
        else if(arr[mid]==0){
            swap(arr[l],arr[mid]);
            l++;
            mid++;
        }
        else{
            swap(arr[mid],arr[h]);
            h--;
        }
    }
}
int main(){
    int arr[]={0,0,0,1,1,2,1,2,1,2,1,1,0,2,1,2,0,1,1,0,0,0,2};
    int z=(sizeof(arr)/4)-1;
    algo(arr,0,z);
    for(auto x:arr){
        cout<<x<<" ";
    }
    return 0;
}