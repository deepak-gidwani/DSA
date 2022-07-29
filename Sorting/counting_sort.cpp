#include<bits/stdc++.h>
using namespace std;
void count_sort(int arr[],int n,int k){  //tc=theta(n+k)
    int count[k]={0};
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    for(int i=1;i<k;i++){
        count[i]+=count[i-1];
    }
    int output[n];
    for(int i=n-1;i>=0;i--){   // used for stability
        output[count[arr[i]]-1]=arr[i];
        count[arr[i]-1]--;
    }
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}
int main(){
    
    return 0;
}