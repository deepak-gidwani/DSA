#include<bits/stdc++.h>
using namespace std;
void bucket_sort(int arr[],int n,int k){   // tc in best case =O(n) and in worst case=O(n*n) ya O(nlogn), as=O(n)
    int mx=*(max_element(arr,arr+n));
    // int range=mx/k;
    mx++;
    vector<int> v[k];
    for(int i=0;i<n;i++){
        int bkt=(k*arr[i])/mx;
        v[bkt].push_back(arr[i]);
    }
    for(int i=0;i<k;i++){
        sort(v[i].begin(),v[i].end());
    }
    int index=0;
    for(int i=0;i<k;i++){
        for(int j=0;j<v[i].size();j++){
            arr[index++]=v[i][j];
        }
    }
    // for(int x:arr) cout<<x<<" "; ye error de rha pta ni kyu
}
int main(){
    int arr[]={30,40,10,80,5,12,70};
    bucket_sort(arr,7,4);
    for(auto x:arr) cout<<x<<" ";
    return 0;
}