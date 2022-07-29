#include<bits/stdc++.h>
using namespace std;
void nk_occ(int arr[],int n,int k){
    unordered_map<int,int> m;
    m.insert({arr[0],1});
    for(int i=1;i<n;i++){
        // if(m.find(arr[i])!=m.end()){  // no need of this commented code
            m[arr[i]]++;   // nahi hoga to bna dega with default value 0 or ++ usse 1 krdega or agr already h to sec value bhda dega
        // }
        // else{
        //     m.insert({arr[i],1});
        // }
    }
    for(auto x:m){
        if(x.second>n/k)
        cout<<x.first<<" "<<x.second<<endl;
    }
}
int main(){
    int arr[]={30,10,20,20,10,20,30,30};
    int n=8,k=4;
    nk_occ(arr,n,k);
    return 0;
}