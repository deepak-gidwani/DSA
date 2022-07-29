#include<bits/stdc++.h>
using namespace std;
void flipflop(bool arr[],int n){
    for(int i=1;i<n;i++){
        if(arr[i]!=arr[i-1]){
            if(arr[i]!=arr[0]){
                cout<<"from "<<i<<" to";
            }
            else cout<<" "<<(i-1)<<endl;
        }
    }
    if(arr[n-1]!=arr[0]) cout<<" "<<n-1;
    // int zero=0,one=0; ye thik ni chl rha
    // for(int j=1;j<n-1;j++){
    //     if(arr[j]!=arr[j-1] && arr[j+1]!=arr[j]){
    //         zero++;
    //         one++;
    //     }
    //     else if(arr[j]==1 && arr[j-1]==1 && arr[j+1]==0){
    //         zero++;
    //     }
    //     else if(arr[j]==0 && arr[j-1]==0 && arr[j+1]==1){
    //         one++;
    //     }
    // }
    // if(arr[0]==0) zero++;
    // else one++;
    // if(arr[n-1]==0) zero++;
    // else one++;

    // return min(zero,one);
}
int main(){
    bool arr[]={0,0,1,0,0,1};
    flipflop(arr,6);
    return 0;
}