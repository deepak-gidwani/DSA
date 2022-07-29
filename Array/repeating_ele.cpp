#include<bits/stdc++.h>
using namespace std;
int repeating(int arr[],int n){
    bool visited[n]={false};
    for(int i=0;i<n;i++){
        if(visited[arr[i]]==true) return arr[i];
        else visited[arr[i]]=true;
    }
    return -1;
}
int main(){
    int arr[]={0,1,2,3,3,4,5};
    cout<<repeating(arr,6);
    return 0;
}